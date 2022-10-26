#ifndef LIST_H
#define LIST_H

#include "Config.h"
#include "Constants.h"
#include <stdbool.h>

struct ListElem
{
    Value_t value;
    size_t  next;
    size_t  prev;
};

struct List
{
    ListElem* data;

    size_t  head_index;
    size_t  tail_index;

    size_t  size;
    size_t  capacity;
    size_t  free;

    bool    is_linear;
};

int ListCtor (List* list);
int ListDtor (List* list);

int ListVerify    (List* list);
int ListTextDump  (List* list);
int ListGraphDump (List* list);

size_t ListElemIndex (List* list, size_t log_index );
size_t ListNext      (List* list, size_t phys_index);
size_t ListPrev      (List* list, size_t phys_index);

size_t  ListHead (List* list);
size_t  ListTail (List* list);

size_t  ListInsertAfter  (List* list, size_t phys_index, Value_t value);
size_t  ListInsertBefore (List* list, size_t phys_index, Value_t value);
Value_t ListErase        (List* list, size_t phys_index);

Value_t ListPopBack   (List* list);
int     ListPushBack  (List* list, Value_t value);
Value_t ListPopFront  (List* list);
int     ListPushFront (List* list, Value_t value);

int ListLinearize (List* list);

int ListClear  (List* list);
int ListResize (List* list);

int ListPrint (List* list);

#endif
