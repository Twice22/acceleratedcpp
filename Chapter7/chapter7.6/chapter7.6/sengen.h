#pragma once
#ifndef _SEN_GEN_
#define _SEN_GEN_

#include <vector>
#include <string>
#include <map>

/* example of Grammar to passed as input to the program
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

/* example of Grammar structure inside the program
Categories				Rules
<noun>					[[cat], [dog], [table]]
<noun-phrase>			[[<noun>], [<adjective> <noun-phrase>]]
<adjective>				[[large], [brown], [absurd]]
<verb>					[[jumps], [sits]]
<location>				[[wherever it wants], [under the sky], [on the stairs]]
<sentence>				[[the <noun-phrase> <verb> <location>]]
*/


typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

Grammar read_grammar(std::istream&);
bool isbracketed(const std::string&s);
int nrand(int n);

void gen_aux(const Grammar&, const std::string&, std::vector<std::string>&);
std::vector<std::string> gen_sentence(const Grammar&);

void display_gensen(const std::vector<std::string>&);

#endif // !_SEN_GEN_
