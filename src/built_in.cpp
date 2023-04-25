#include "built_in.hpp"

static void built_in_print_bools(bool ln)
{
    Node *node = new Node;
    node->token = new_token(Token::TOK_ID, ln ? "println" : "print", 0, 0, "");
    node->type = Node::NODE_FUN_DEC;

    Node *in = new Node, *out = new Node;
    in->type = Node::NODE_FUN_IN;
    out->type = Node::NODE_FUN_OUT;

    node->children.push_back(in);
    node->children.push_back(out);

    Node *num = new Node, *nil = new Node;
    num->token = new_token(Token::KEY_BOOL, "bool", 0, 0, "");
    nil->token = new_token(Token::KEY_NIL, "nil", 0, 0, "");

    in->children.push_back(num);
    out->children.push_back(nil);

    node->type_scheme = TypeScheme(TypeScheme::FUN_TYPE);
    node->type_scheme.fun_type.first.push_back(type_names["bool"]);
    node->type_scheme.fun_type.second.push_back(type_names["nil"]);

    ln ? functions["println"].insert(node) : functions["print"].insert(node);
}

static void built_in_print_nums(bool ln)
{
    Node *node = new Node;
    node->token = new_token(Token::TOK_ID, ln ? "println" : "print", 0, 0, "");
    node->type = Node::NODE_FUN_DEC;

    Node *in = new Node, *out = new Node;
    in->type = Node::NODE_FUN_IN;
    out->type = Node::NODE_FUN_OUT;

    node->children.push_back(in);
    node->children.push_back(out);

    Node *num = new Node, *nil = new Node;
    num->token = new_token(Token::KEY_NUM, "num", 0, 0, "");
    nil->token = new_token(Token::KEY_NIL, "nil", 0, 0, "");

    in->children.push_back(num);
    out->children.push_back(nil);

    node->type_scheme = TypeScheme(TypeScheme::FUN_TYPE);
    node->type_scheme.fun_type.first.push_back(type_names["num"]);
    node->type_scheme.fun_type.second.push_back(type_names["nil"]);

    ln ? functions["println"].insert(node) : functions["print"].insert(node);
}

void initialize_built_ins()
{
    built_in_print_nums(false);
    built_in_print_nums(true);

    built_in_print_bools(false);
    built_in_print_bools(true);
}

void free_built_ins()
{
    for (auto node : functions["print"])
    {
        free_tree(node);
    }

    for (auto node : functions["println"])
    {
        free_tree(node);
    }
}
