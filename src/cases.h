#ifndef _CASES_H
#define _CASES_H

#include <stdio.h>
#include <stdlib.h>

void dump_elf_header(elf_t *elf);
void dump_program_headers(elf_t *elf);
void dump_section_headers(elf_t *elf);
void dump_symbol_table(elf_t *elf);

#endif 