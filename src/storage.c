#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "storage.h"

WebSiteInfo create_website(const char *nameSite, const char * username, const char *password) {
  WebSiteInfo newSite;

  strcpy(newSite.siteName, nameSite);
  strcpy(newSite.user, username);
  strcpy(newSite.pass, password);

  return newSite;
}

bool can_add_new(Storage *s, const char *nameSite) {
  WebSiteInfo *list = s->entries;

  for (size_t i = 0; i < s->count; i++) {
    char *site = list[i].siteName;
    if(strcmp(site, nameSite) == 0) return false;
  }

  return true;
}


void storage_init(Storage *s) {
  s->count = 0;
  s->capacity = 4;
  s->entries = malloc(sizeof(WebSiteInfo) * s->capacity);

  if(s->entries == NULL) {
    printf("Impossibile allocare la memoria\n");
    exit(1);
  }
}

void storage_add(Storage *s, WebSiteInfo newSite) {

  if(!can_add_new(s, newSite.siteName)) {
    printf("Questo sito è stato già inserito!\n");
    return ;
  }

  if(s->count == s->capacity) {
    size_t new_capacity = s->capacity * 2;
    WebSiteInfo *tmp = realloc(s->entries, sizeof(WebSiteInfo) * new_capacity);
    if(!tmp) return;
    s->entries = tmp;
    s->capacity = new_capacity;
  }

  s->entries[s->count] = newSite;
  s->count++;
}

void storage_remove(Storage *s, size_t index) {
  if(index >= s->count) return;

  for(size_t i = index; i < s->count; i++) {
    s->entries[i] = s->entries[i + 1];
  }

  s->count--;

  // todo: manage realloc
}

void storage_free(Storage *s) {
  if(s->entries) {
    free(s->entries);
    s->entries = NULL;
  }

  s->count = 0;
  s->capacity = 0;
}

void storage_list(const Storage *s) {
  if(s->count == 0) {
    printf("Non hai salvato niente. \n");
    return;
  }

  printf("Siti che hai salvato: \n");
  for (size_t i = 0; i < s->count; i++) {
    printf("[%d] %s - %s - %s\n",
      i + 1,
      s->entries[i].siteName,
      s->entries[i].user,
      s->entries[i].pass
    );
  }
}

void storage_save_as_file(const Storage *s) {
  FILE *f = fopen("storage.bin", "wb");
  if(!f) {
    printf("Errore: impossibile aprire il file per il salvataggio.\n");
    return;
  }

  fwrite(&s->count, sizeof(int), 1, f);
  fwrite(s->entries, sizeof(WebSiteInfo), s->count, f);

  fclose(f);

  printf("Dati salvati correttamente!\n");
}

void storage_load_file(Storage *s) {
  FILE *f = fopen("storage.bin", "rb");
  if(!f) {
    printf("Nessun file da caricare!\n");
    return;
  }

  int count;
  fread(&count, sizeof(int), 1, f);
  
  s->count = count;
  s->capacity = count > 0 ? count : 4;
  s->entries = malloc(s->capacity * sizeof(WebSiteInfo));

  if(!s->entries) {
    printf("Errore: allocazione memoria da lettura file\n");
    fclose(f);
    exit(1);
  }

  fread(s->entries, sizeof(WebSiteInfo), count, f);
  fclose(f);
  printf("Dati caricati correttamente!\n");
}