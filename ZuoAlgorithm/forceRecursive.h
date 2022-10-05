#pragma once
#include <string>
#include <stack>
#include "common.h"


void hanota(vector<int>& from, vector<int>& help, vector<int>& to);
vector<string> getAllSubStr(string src);
vector<string> getAllPossibleStr(string src);
vector<string> getAllPossibleStrNoRepeat(string src);
int playCards(vector<int>& cards);