#ifndef PRIVATE_SHODDY_H_INCLUDE
#define PRIVATE_SHODDY_H_INCLUDE
#include <stdio.h>
#include "MEM.h"
#include "SDY.h"
#include "SDY_dev.h"

#define smaller(a,b) (a)<(b)?(a):(b)
#define larger(a,b) (a)>(b)?(a):(b)

#define MESSAGE_ARGUMENT_MAX (256)
#define LINE_BUF_SIZE (1024)

typedef enum {
    PARSE_ERR = 1,
    CHARACTER_INVALID_ERR,
    FUNCTION_MULIPLE_DEFINE_ERR,
    COMPILE_ERROR_COUNT_PLUS_1,
}CompileError;

typedef enum {
   EXPRESSION_STATEMENT = 1,
   GLOBAL_STATEMENT, 
   IF_STATEMENT,
   WHILE_STATEMENT,
   FOR_STATEMENT,
   RETURN_STATEMENT,
   BREAK_STATEMENT,
   CONTINUM_STATEMENT,
   STATEMENT_TYPE_COUNT_PLUS_1,
}StatementType;

typedef enum {
    BOOLEAN_EXPRESSION = 1,
    INT_EXPRESSION,
    DOUBLE_EXPRESSION,
    STRING_EXPRESSION,
    IDENTIFIER_EXPRESSION,
    ASSIGN_EXPRESSION,
    ADD_EXPRESSION,
    SUB_EXPRESSION,
    MUL_EXPRESSION,
    DIV_EXPRESSION,
    MOD_EXPRESSION,
    EQ_EXPRESSION,
    NE_EXPRESSION,
    GT_EXPRESSION,
    GE_EXPRESSION,
    LT_EXPRESSION,
    LE_EXPRESSION,
    LOGICAL_AND_EXPREESSION,
    LOGICAL_OR_EXPRESSION,
    MINUS_EXPRESSION,
    FUNCTION_CALL_EXPRESSION,
    NULL_EXPRESSION,
    EXPRESSION_TYPE_COUNT_PLUS_1,
}ExpressionType;

typedef struct Expression_tag {
    ExpressionType type;
    int line_number;
    union {
        sdy_tBoolean           boolean_value;
        int                    int_value;
        double                 double_value;
        char                   *string_value;
        char                   *identifier;
        AssignExpression       assign_expression;
        BinaryExpression       binary_expression;
        struct                 Expression_tag *minus_expression;
        FunctionCallExpression function_call_expression;
    }u;
}Expression;

typedef struct StatementList_tag {
    Statement *statement;
    struct StatementList_tag *next;
}StatementList;

typedef struct {
   StatementList *statement_list; 
}Block;

typedef struct ParameterList_tag {
    char* name;
    struct ParameterList_tag* next;
}ParameterList;

typedef struct IdentifierList_tag {
    char *name;
    struct IdentifierList_tag *next;
}IdentifierList;

typedef struct {
    IdentifierList *identifier_list;
}GlobalStatement;

typedef struct {
    Expression *condition;
    Block      *then_block;
    Elseif     *elseif_list;
    Block      *else_block;
}IfStatement;

typedef struct {
    Expression *condition;
    Block      *block;
}WhileStatement;

typedef struct {
    Expression *init;
    Expression *condition;
    Expression *action;
    Block      *block;
}ForStatement;

typedef struct {
    Expression *return_value;
}ReturnStatement;

typedef struct Statement_tag {
   StatementType type;
   int line_number;
   union {
       Expression      *expression_s;
       GlobalStatement global_s;
       IfStatement     if_s;
       WhileStatement  while_s;
       ForStatement    for_s;
       ReturnStatement return_s;
  }u;
}Statement;

typedef enum {
    SHODDY_FUNCTION_DEFINITION = 1,
    NATIVE_FUNCTION_DEFINITION,
}FunctionDefinitionType;

typedef struct FunctionDefinition_tag {
    char *name;
    FunctionDefinitionType type;
    union {
        struct {
            ParameterList *parameters;
            Block *block;
        }shoddy_f;
        struct {
            sdy_NativeFunctionProc *proc;
        }native_f;
    }u;
    struct FunctionDefinition_tag *next;
}FunctionDefinition;
#endif