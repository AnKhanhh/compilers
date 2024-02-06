#ifndef COMP_LIST_SYMBOL_TABLE_H
#define COMP_LIST_SYMBOL_TABLE_H

const char *IDENTTYPE[] = {
		"SB_INT", "SB_CONST_INT", "SB_FUNCTION", "SB_ARRAY"
};

typedef struct SymbolEntry {
    char ident[LEXEME_LENGTH];
    enum EIdentType {
        SB_INT, SB_CONST_INT, SB_FUNCTION, SB_ARRAY
    } type;
    union {
        int const_value;
        union {
            int is_initialized;
            int value;
        } var;
        int arr_size;
        union {
            int arg_count;
            struct SymbolTable *ptr;
        } func;
    } data;
} SymbolEntry;

typedef struct SymbolTable {
    char table_name[LEXEME_LENGTH];
    struct SymbolTable *parent;
    int entry_count;
    struct SymbolEntry *entries;
} SymbolTable;

//  allocate a new table, return its pointer
SymbolTable *NewSymbolTable(SymbolTable *parent_ptr, char *name) ;
//  insert an entry into parent table, parent must exist
SymbolTable *InsertEntry(SymbolTable *parent, SymbolEntry entry) ;
//  DFS recursive free()
void FreeSymbolTables(SymbolTable *root) ;

SymbolTable *NewSymbolTable(SymbolTable *parent_ptr, char *name) {
    SymbolTable *new_table = calloc(1, sizeof(SymbolTable));
    if (parent_ptr) new_table->parent = parent_ptr;
    return new_table;
}

SymbolTable *InsertEntry(SymbolTable *parent, SymbolEntry entry) {
    assert(parent != NULL);
    if (parent->entry_count == 0) {
        parent->entries = malloc(sizeof(SymbolEntry));
        assert(parent->entries != NULL);
    }
    parent->entries[parent->entry_count++] = entry;
    return parent;
}

void FreeSymbolTables(SymbolTable *root) {
    if (root->entries != NULL) {
        assert(root->entry_count > 0);
        for (int i = 0; i < root->entry_count; ++i) {
            if (root->entries[i].type == SB_FUNCTION)
                FreeSymbolTables(root->entries[i].data.func.ptr);
        }
        free(root->entries);
    }
    free(root);
}

#endif //COMP_LIST_SYMBOL_TABLE_H
