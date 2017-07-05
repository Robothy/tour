#ifndef ALERT_INFO_H
#define ALERT_INFO_H

char *welcome_info =
"Welcome to use tourism information manage system.\n\
1312441116\t Jiang Xiaodong.\n\
Use \"help\" for more information about command. \n";

char *welcome_panel_help =
"Login\n\
    Usage \tlogin -u UserID -p UserPassword\n\
    Example \tlogin -u 001 -p 001\n\
Register an Account\n\
    Usage\tregister -u UserID\n\
    Example\tregister -u 001\n";

char *tourist_panel_help =
"Sign Up\n\
    Usage:\tsignup -l AttractionName -d Date\n\
    Example:\tsignup -l ShangHai -d 2017-05-08\n\
Cancel\n\
    Usage:\tcancel -l AttractionName -d Date\n\
    Example:\tcancel -l Sanpaolo -d 2017-11-11\n\
Query\n\
    Usage:query signedup | unsignedup \n\
    Example:\tquery signedup (Query signed up info) , query unsignedup (Query unsigned up info).\n";

char *admin_panel_help =
"Add Attraction\n\
    Usage:\tadd -n AttractionName -d Date\n\
    Example:\tadd -n ShangHai -d 2017-09-10\n\
Delete Attraction\n\
    Usage:\tdel -n AttractionName -d Date\n\
    Example:\tdel -d 2017-09-09 -n XiangShan \n\
Count\n\
    Usage:\tcount groups | tourists\n\
    Example:\tcount groups , count tourists\n";

#endif // ALERT_INFO_H
