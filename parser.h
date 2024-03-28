/* 
 * parse.h
 * Programming Assignment 2
 * spring 2023
*/

#ifndef PARSE_H_
#define PARSE_H_

#include <iostream>

using namespace std;

#include "lex.h"



extern bool Prog(istream& in, int& line);
extern bool StmtList(istream& in, int& line);
extern bool Stmt(istream& in, int& line);
extern bool WritelnStmt(istream& in, int& line);
extern bool IfStmt(istream& in, int& line);
extern bool AssignStmt(istream& in, int& line);
extern bool Var(istream& in, int& line);
extern bool ExprList(istream& in, int& line);
extern bool Expr(istream& in, int& line);
extern bool RelExpr(istream& in, int& line);
extern bool AddExpr(istream& in, int& line);
extern bool MultExpr(istream& in, int& line);
extern bool ExponExpr(istream& in, int& line);
extern bool UnaryExpr(istream& in, int& line);
extern bool PrimaryExpr(istream& in, int& line, int sign);
extern int ErrCount();

#endif /* PARSE_H_ */


/*Prog ::= StmtList
2. StmtList ::= Stmt ;{ Stmt; }
3. Stmt ::= AssignStme | WriteLnStmt | IfStmt
4. WriteLnStmt ::= writeln (ExprList)
5. IfStmt ::= if (Expr) ‘{‘ StmtList ‘}’ [ else ‘{‘ StmtList ‘}’ ]
6. AssignStmt ::= Var = Expr
7. Var ::= NIDENT | SIDENT
8. ExprList ::= Expr { , Expr }
9. Expr ::= RelExpr [(-eq|==) RelExpr ]
10. RelExpr ::= AddExpr [ ( -lt | -gt | < | > ) AddExpr ]
11. AddExpr :: MultExpr { ( + | - | .) MultExpr }
12. MultExpr ::= ExponExpr { ( * | / | **) ExponExpr }
13. ExponExpr ::= UnaryExpr { ^ UnaryExpr }
14. UnaryExpr ::= [( - | + )] PrimaryExpr
15. PrimaryExpr ::= IDENT | SIDENT | NIDENT | ICONST | RCONST | SCONST
| (Expr)*/
