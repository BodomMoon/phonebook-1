#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 20

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define OPT 1
#define BST 1

typedef struct __PHONE_BOOK_DETAIL_ENTRY {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} detail;

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_BOOK_ENTRY *pLeft;
    struct __PHONE_BOOK_ENTRY *pRight;
    detail *pDetail;
} entry;


entry *findName(char lastName[], entry *pHead);
void append(char lastName[], entry *e);

#endif
