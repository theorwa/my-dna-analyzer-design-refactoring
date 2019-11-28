#include <cli/cli.h>
#include <db/db.h>
#include <dna/dna.h>
#include <controller/analyzer.h>

int main()
{
   Cli *cli = new Cli();
   DB<Dna*> *dnaDB = new DB<Dna*>();
   Analyzer analyzer(cli, dnaDB);
   analyzer.start();
   return 0;
}
