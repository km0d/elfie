#ifndef _ELFIE_H
#define _ELFIE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <elf.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct elf {
  Elf64_Ehdr *elf_header;
  Elf64_Phdr *elf_program_header;
  Elf64_Shdr *elf_section_header;
  Elf64_Sym *elf_symbol_table;
  char *file;
  char *string_table;
} elf_t;

elf_t *init_elf(int fd);
void get_elf_header(elf_t *elf);
void destroy_parser(int fd, char *file, elf_t *elf);
void process_file(const char *filename);
void error_handling(int fd, elf_t *elf, char *file, const char *reason);

#endif
