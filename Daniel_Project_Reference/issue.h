typedef char* Severity;
#define Trivial "Trivial"
#define Normal "Normal"
#define Critical "Critical"

typedef struct issue_def{
	int issueId;
	char* summary;
	Severity severity;
	char* reporter;	
}Issue;

void printIssue(Issue* issue);
Issue* getIssueDetails();
char* copyString(char* string);