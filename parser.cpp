/* Implementation of Recursive-Descent Parser
 * parser.cpp
 * Programming Assignment 2
 * Spring 2023
*/

#include "parser.h"

map<string, bool> defVar;
map<string, Token> SymTable;
using namespace std;

namespace Parser {
	bool pushed_back = false;
	LexItem	pushed_token;

	static LexItem GetNextToken(istream& in, int& line) {
		if( pushed_back ) {
			pushed_back = false;
			return pushed_token;
		}
		return getNextToken(in, line);
	}

	static void PushBackToken(LexItem & t) {
		if( pushed_back ) {
			abort();
		}
		pushed_back = true;
		pushed_token = t;	
	}

}

static int error_count = 0;

int ErrCount()
{
    return error_count;
}

void ParseError(int line, string msg)
{
	++error_count;
	cout << error_count << ". Line # " << line << ": " << msg << endl;
}


bool Prog(istream& in, int& line){	
	LexItem t;	
	while(StmtList(in, line)){
		t = Parser::GetNextToken(in, line);
		if(t == DONE){
			if(ErrCount() == 0){
				cout<<"(DONE)"<<endl;
				return true;
			}
			else
				return false;
		}
		else{
			Parser::PushBackToken(t);
			continue;
	}
	}

	ParseError(line, "Expected StmtList");
	return false;

}


bool StmtList(istream& in, int& line){
	bool status = false;
	//cout << "in StmtList and before calling Stmt" << endl;
	status = Stmt(in, line);
	if(!status){
		ParseError(line, "Missing Statement");
		return false;
	}
	
	LexItem tok = Parser::GetNextToken(in, line);
	
	if (tok == SEMICOL) {
		//cout << "before calling StmtList" << endl;
		while(Stmt(in, line)){
			tok = Parser::GetNextToken(in, line);
			if ( tok == RBRACES){
				//cout<<"found braces"<<endl;
				Parser::PushBackToken(tok);
				//cout<<"new curr tok: "<<tok.GetLexeme()<<endl;
				return true;
			}

			/*if(tok != RBRACES)
				LexItem tok = Parser::GetNextToken(in, line);*/
			else{
				Parser::PushBackToken(tok);
				//return true;
				//cout<<"pushed back tok: " << tok.GetLexeme() << endl;
			}

			tok = Parser::GetNextToken(in, line);
			continue;
		}
		
		//cout << "after calling StmtList" << endl;
	}
	else{
		ParseError(line, "missing semicolon after expression!!" + tok.GetLexeme());
		return false;
	}
	return true;

}

bool Stmt(istream& in, int& line){
	LexItem t = Parser::GetNextToken(in, line);
	if(t == NIDENT || t == SIDENT){
		Parser::PushBackToken(t);
		if(AssignStmt(in, line)) 
			return true;
	}
	if (t == WRITELN){
		if(WritelnStmt(in, line)) 
			return true;
		else{
			ParseError(line, "Incorrect writeln stmt");
			return false;
		}

	}
	else if (t == IF){
		if(IfStmt(in, line))
			return true;
		else{
			ParseError(line, "Incorrect if stmt");
			return false;
		}
	}
	else if(t== RBRACES){
		//cout<<"pushed back tok 2: " << t.GetLexeme() << endl;

		Parser::PushBackToken(t);
		return true;
	}
	else {
		//ParseError(line, "Expected Stmt not found");
		Parser::PushBackToken(t);
		return false;
	}

    return true;
}




//WritelnStmt:= WRITELN (ExpreList) 
bool WritelnStmt(istream& in, int& line) {
	LexItem t;
	//cout << "in Writeln Stmt" << endl;
	
	t = Parser::GetNextToken(in, line);
	if( t != LPAREN ) {
		
		ParseError(line, "Missing Left Parenthesis of Writeln Statement");
		return false;
	}
	
	bool ex = ExprList(in, line);
	
	if( !ex ) {
		ParseError(line, "Missing expression list after Print");
		return false;
	}
	
	t = Parser::GetNextToken(in, line);
	if(t != RPAREN ) {
		
		ParseError(line, "Missing Right Parenthesis of Writeln Statement");
		return false;
	}
	//Evaluate: print out the list of expressions values

	return true;
}//End of WritelnStmt

bool IfStmt(istream& in, int& line){
	LexItem t = getNextToken(in, line);
	

	/*if(t != IF){
		ParseError(line, "Missing if in Ifstmt");
		return false;
	}*/

	if(t!= LPAREN){
		ParseError(line, "missing lparen");
		return false;
	}
	//t = getNextToken(in, line); //THIS LINE CAUSES A SEGMENTATION ERROR (?)
	if(!Expr(in, line)){
		ParseError(line, "Missing expression in Ifstmt");
		return false;
	}
	//Parser::PushBackToken(t);
	

	//cout << "Current Tok: " <<Parser::GetNextToken(in, line).GetLexeme()<< endl;

	t = Parser::GetNextToken(in, line);
	//cout << "Current Tok: " <<t.GetLexeme()<< endl;*/

	if(t!= RPAREN){
		ParseError(line, "missing rparen  ");

		return false;
	}
	t = Parser::GetNextToken(in, line);


	if(t!= LBRACES){
		ParseError(line, "missing lbraces");
		return false;
	}
	//cout<<"current token: " << t.GetLexeme()<<endl;
	//t = Parser::GetNextToken(in, line);

	if(!StmtList(in, line)){
		ParseError(line, "Missing statement");
		return false;
	}
	//Parser::PushBackToken(t);
	//cout<<"Stmtlist is true"<<endl;
	//t = Parser::GetNextToken(in, line);
	t = Parser::GetNextToken(in, line);

	//cout<<"current token: " << t.GetLexeme()<<endl;
	
	if(t!= RBRACES){
		ParseError(line, "missing rbraces 1");
		ParseError(line, "missing if stmt clause  ");

		return false;
	}
	t = Parser::GetNextToken(in, line);
	//cout<<"current token: " << t.GetLexeme()<<endl;

	if(t == ELSE){
		t = Parser::GetNextToken(in, line);
		//cout<<t.GetLexeme()<<endl;

		if(t!= LBRACES){
			ParseError(line, "missing lbraces!");
			return false;
		}

		if(!StmtList(in, line)){	
		ParseError(line, "Missing statement");
		return false;
		}

		t = Parser::GetNextToken(in, line);

		if(t!= RBRACES){
			ParseError(line, "missing rbraces 2");
			return false;
		}
	}
	else
		Parser::PushBackToken(t);
	
	return true;


}


bool AssignStmt(istream& in, int& line){
	/*To check if value is valid type of var
	string lex = t.GetLexeme();//.substr(0,1);
	//defVar.insert(lex, true);
	Parser::PushBackToken(t); */
	//LexItem t = Parser::GetNextToken(in, line);

	if(!Var(in, line)){
		//ParseError(line, "Expected variable name");
		return false;
	}

	LexItem t = Parser::GetNextToken(in, line);

	if(t != ASSOP){
		ParseError(line, "Expected equal sign");
		return false;
	}

	if(!(Expr(in, line))){
		ParseError(line, "Expected expression in assign");
		return false;
	}
	return true;


		
}

bool Var(istream& in, int& line){
	LexItem t = Parser::GetNextToken(in, line);
	if(t!= NIDENT && t != SIDENT){
		ParseError(line, "Expected variable name");
		return false;
	}
	defVar[t.GetLexeme()] = true;
	return true;	
}






//ExprList:= Expr {,Expr}
bool ExprList(istream& in, int& line) {
	bool status = false;
	//cout << "in ExprList and before calling Expr" << endl;
	status = Expr(in, line);
	if(!status){
		ParseError(line, "Missing Expression");
		return false;
	}
	
	LexItem tok = Parser::GetNextToken(in, line);
	
	if (tok == COMMA) {
		//cout << "before calling ExprList" << endl;
		status = ExprList(in, line);
		//cout << "after calling ExprList" << endl;
	}
	else if(tok.GetToken() == ERR){
		ParseError(line, "Unrecognized Input Pattern");
		//cout << "(" << tok.GetLexeme() << ")" << endl;
		return false;
	}
	else{
		Parser::PushBackToken(tok);
		return true;
	}
	return status;
}//End of ExprList


bool Expr(istream& in, int& line){

	if(!RelExpr(in, line)){
		ParseError(line, "Expected different expression");
		return false;
	}
	LexItem t = Parser::GetNextToken(in, line);

	if(t != SEQ && t != ASSOP){
		Parser::PushBackToken(t);
		return true;
	}
	else{

		if(!RelExpr(in, line)){
			//ParseError(line, "Expected rel expression");
			return false;
		}
		//cout << "Next Tok: " <<Parser::GetNextToken(in, line).GetLexeme()<< endl;




	return true;
}
}



bool RelExpr(istream& in, int& line){
	if(!AddExpr(in, line)){
		//ParseError(line, "Expected different expression");
		return false;
	}
	LexItem t = Parser::GetNextToken(in, line);
	if(t != NLTHAN  && t != SLTHAN && t!=SGTHAN && t != NGTHAN ){
		Parser::PushBackToken(t);
		return true;
	}
	else{
		//Parser::PushBackToken(t);

		if(!AddExpr(in, line)){
			//ParseError(line, "Expected add expression");
			return false;
		}


	return true;

}
}


bool AddExpr(istream& in, int& line){
	if(!MultExpr(in, line)){
		//ParseError(line, "Expected different expression");
		return false;
	}
	LexItem t = Parser::GetNextToken(in, line);
	//bool valid = false;
	if(t != PLUS  && t != MINUS && t!=CAT){
		Parser::PushBackToken(t);
		return true;
	}
	while(true){
		if(!MultExpr(in, line)){
			//ParseError(line, "Expected mult expression");
			return false;
		}
		t = Parser::GetNextToken(in, line);
		if(t != PLUS  && t != MINUS && t!=CAT){
			Parser::PushBackToken(t);
			return true;
	}


	return true;

}

}


bool MultExpr(istream& in, int& line){
	if(!ExponExpr(in, line)){
	//ParseError(line, "Expected different expression");
	return false;
	}
	LexItem t = Parser::GetNextToken(in, line);
	if(t != SREPEAT  && t != DIV && t!=MULT){
		Parser::PushBackToken(t);
		return true;
	}
	while(true){
		if(!ExponExpr(in, line)){
			//ParseError(line, "Expected expon expression");
			return false;
		}
		t = Parser::GetNextToken(in, line);
		if(t != SREPEAT  && t != DIV && t!=MULT){
			Parser::PushBackToken(t);
			return true;
}
}
}

bool ExponExpr(istream& in, int& line){
	if(!UnaryExpr(in, line)){
	//ParseError(line, "Expected different expression");
	return false;
	}
	LexItem t = Parser::GetNextToken(in, line);
	if(t != EXPONENT){
		Parser::PushBackToken(t);
		return true;
	}
	while(true){
		if(!UnaryExpr(in, line)){
			//ParseError(line, "Expected unary expression");
			return false;
		}
		t = Parser::GetNextToken(in, line);
		if(t != EXPONENT){
			Parser::PushBackToken(t);
			return true;
}
}
}

bool UnaryExpr(istream& in, int& line){
	LexItem t = Parser::GetNextToken(in, line);
	if(t != MINUS && t!= PLUS)
		
		//t = Parser::GetNextToken(in, line);
	//else
		Parser::PushBackToken(t);

	//Parser::PushBackToken(t); //CAUSES AN ERROR

	
	if(!PrimaryExpr(in, line, 1)){
		//ParseError(line, "expected primary expr");
		return false;
	}
	return true;
}

bool PrimaryExpr(istream& in, int& line, int sign){
	LexItem t = Parser::GetNextToken(in, line);
	if(t != IDENT && t!= SIDENT  && t!= NIDENT && t!= ICONST && t!= RCONST && t!= SCONST/* && !Expr(in, line)*/){
		if(t == LPAREN){
			if(Expr(in, line)){
				t = Parser::GetNextToken(in, line);
				if(t == RPAREN)
					return true;
			}
		}
		//ParseError(line, "expected different token");
		return false;
		
		}
	/*else{	
		ParseError(line, "expected different token");

		return false;
	}*/
	if(t == SIDENT || t==NIDENT){
		if(defVar.find(t.GetLexeme()) == defVar.end()){
			ParseError(line, "Undefined variable");
			return false;
		}

	}
		return true;

}

