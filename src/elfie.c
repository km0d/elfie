/**
 * @file elfie.c
 * @author 0xff (0xff@0xff.0xff)
 * @brief ELF Parser.
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022 0xff
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "all.h"

/**
 * @brief Returns the size of the ELF file.
 * 
 */

static inline __attribute__((always_inline)) size_t get_elf_size(int fd) {
  struct stat st_stat = {0};

  return ((fstat(fd, &st_stat) == -1) ? 0 : st_stat.st_size);
}

/**
 * @brief Returns a pointer to the mapped file in memory.
 * 
 */

static inline __attribute__((always_inline)) char *map_elf_file(int fd) {
  char *file = mmap(NULL, get_elf_size(fd), PROT_READ, MAP_PRIVATE, fd, 0);

  return (!file ? NULL : file);
}

/**
 * @brief Checks if the file mapped in memory is actually an ELF file or not.
 * 
 */

static inline __attribute__((always_inline)) bool check_magic_bytes(const char *file) {
  return ((memcmp(file, (char []){0x7f, 0x45, 0x4c, 0x46}, 4)
          || memcmp(file, (char []){0x46, 0x4c, 0x45, 0x7f}, 4)) ? true : false);
}

/**
 * @brief In case of an error, this will handle it nicely.
 * 
 * @param fd The file descriptor of the file we opened.
 * @param elf A pointer to the struct.
 * @param file The file that was mapped into memory. 
 * @param reason The reason. Duh.
 */

void error_handling(int fd, elf_t *elf, char *file, const char *reason) {
  fprintf(stderr, "%s\n", reason);
  munmap(file, get_elf_size(fd));
  close(fd);
  free(elf);
  exit(EXIT_FAILURE);
}

/**
 * @brief Opens the file, maps the file into memory, parses it and dumps the elf header.
 *
 * @param path The path of the ELF file we are going to inspect.
 */

elf_t *init_elf(int fd) {
  elf_t *elf = calloc(1, sizeof(elf_t));

  if (!elf)
    error_handling(fd, NULL, NULL, "Failed to allocate memory for the struct!");

  if (!(elf->file = map_elf_file(fd)))
    error_handling(fd, elf, elf->file, "Failed to map the file into memory!");

  if (!check_magic_bytes(elf->file))
    error_handling(fd, elf, elf->file, "The file provided is not an ELF file.");

  elf->elf_header = (Elf64_Ehdr *)elf->file;
  elf->elf_program_header = (Elf64_Phdr *)(elf->file + elf->elf_header->e_phoff);
  elf->elf_section_header = (Elf64_Shdr *)(elf->file + elf->elf_header->e_shoff);
  elf->string_table = elf->file + elf->elf_section_header[elf->elf_header->e_shstrndx].sh_offset;

  return elf;
}

/**
 * @brief Frees all the allocated memory, thus "destroying" the parser.
 * 
 * @param fd The file descriptor of the file we inspected.
 * @param file The mapped file in memory.
 * @param elf The pointer to the struct.
 */

void destroy_parser(int fd, char *file, elf_t *elf) {
  munmap(file, get_elf_size(fd));
  free(elf);
  close(fd);
}
