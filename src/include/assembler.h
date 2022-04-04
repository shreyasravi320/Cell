#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include "parser.h"

std::string assemble_unary(Node *root);
std::string assemble_binary(Node *root);
std::string assemble_expr(Node *root);
std::string assemble_statement(Node *root);
std::string assemble_function(Node *root);
std::string assemble_program(Node *root);
void assemble_nasm(std::string filename, Node *root);

#endif