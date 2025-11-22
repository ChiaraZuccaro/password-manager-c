#ifndef STORAGE_H
#define STORAGE_H

typedef struct {
  char siteName[50];
  char user[50];
  char pass[50];
} WebSiteInfo;

typedef struct {
  WebSiteInfo *entries;
  int count;
  int capacity;
} Storage;

// Funzioni
void storage_init(Storage *s);
void storage_add(Storage *s, WebSiteInfo newSite);
void storage_remove(Storage *s, char *nameSite);
void storage_free(Storage *s);

void storage_list(const Storage *s);

void storage_save_as_file(const Storage *s);
void storage_load_file(Storage *s);

#endif
