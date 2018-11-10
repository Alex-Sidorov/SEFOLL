#ifndef SECURITY_H
#define SECURITY_H

#include <QString>

enum class Access { GUEST , CHIEF , WORKER_TAKE_ORDER, WORKER_CLOSE_ORDER, ADMIN};

class Security
{
public:
    static void change_access();
    static void delete_user();
    static void add_user();
    static void change_password();
};


#endif // SECURITY_H
