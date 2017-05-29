#pragma once
#ifndef _SEN_GEN_
#define _SEN_GEN_

#include <vector>
#include <string>
#include <list>
#include <map>

/* example of Grammar
Categories				Rules
<noun>					cat
<noun>					dog
<noun>					table
<noun-phrase>			<noun>
<noun-phrase>			<adjective> <noun-phrase>
<adjective>				large
<adjective>				brown
<adjective>				absurd
<verb>					jumps
<verb>					sits
<location>				wherever it wants
<location>				under the sky
<location>				on the stairs
<sentence>				the <noun-phrase> <verb> <location>
*/


typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

Grammar read_grammar(std::istream&);
bool isbracketed(const std::string&s);
int nrand(int n);

void gen_aux(const Grammar&, const std::string&, std::list<std::string>&);
std::list<std::string> gen_sentence(const Grammar&);

void display_gensen(const std::list<std::string>&);

#endif // !_SEN_GEN_
