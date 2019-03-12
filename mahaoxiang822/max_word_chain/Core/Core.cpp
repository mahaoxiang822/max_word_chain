#include "stdafx.h"

#include "Core.h"
#include "Solve.h"

int Core::gen_chain_word(char * words[], int len, char * result[], char head, char tail, bool enable_loop)
{
	Solver solver;
	return solver.gen_chain_word(words, len, result, head, tail, enable_loop); // TODO more setting for head, tail, enable_loop
}

int Core::gen_chain_char(char * words[], int len, char * result[], char head, char tail, bool enable_loop)
{
	Solver solver;
	return solver.gen_chain_char(words, len, result, head, tail,  enable_loop); // TODO more setting for head, tail, enable_loop
}