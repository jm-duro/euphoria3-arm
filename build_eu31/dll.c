// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _17open_dll(int _file_name)
{
    int _3953 = 0;
    int _0, _1, _2;
    

    //     return machine_func(M_OPEN_DLL, file_name)
    _3953 = machine(50, _file_name);
    DeRefDS(_file_name);
    return _3953;
    ;
}


int _17define_c_var(int _lib, int _variable_name)
{
    int _3954 = 0;
    int _0, _1, _2;
    

    //     return machine_func(M_DEFINE_VAR, {lib, variable_name})
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _lib;
    Ref(_lib);
    ((int *)_2)[2] = _variable_name;
    RefDS(_variable_name);
    _3954 = MAKE_SEQ(_1);
    _0 = _3954;
    _3954 = machine(56, _3954);
    DeRefDS(_0);
    DeRef(_lib);
    DeRefDS(_variable_name);
    return _3954;
    ;
}


int _17define_c_proc(int _lib, int _routine_name, int _arg_types)
{
    int _3956 = 0;
    int _0, _1, _2;
    

    //     return machine_func(M_DEFINE_C, {lib, routine_name, arg_types, 0})
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_lib);
    *((int *)(_2+4)) = _lib;
    Ref(_routine_name);
    *((int *)(_2+8)) = _routine_name;
    RefDS(_arg_types);
    *((int *)(_2+12)) = _arg_types;
    *((int *)(_2+16)) = 0;
    _3956 = MAKE_SEQ(_1);
    _0 = _3956;
    _3956 = machine(51, _3956);
    DeRefDS(_0);
    DeRef(_lib);
    DeRef(_routine_name);
    DeRefDS(_arg_types);
    return _3956;
    ;
}


int _17define_c_func(int _lib, int _routine_name, int _arg_types, int _return_type)
{
    int _3958 = 0;
    int _0, _1, _2;
    

    //     return machine_func(M_DEFINE_C, {lib, routine_name, arg_types, return_type})
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_lib);
    *((int *)(_2+4)) = _lib;
    Ref(_routine_name);
    *((int *)(_2+8)) = _routine_name;
    RefDS(_arg_types);
    *((int *)(_2+12)) = _arg_types;
    Ref(_return_type);
    *((int *)(_2+16)) = _return_type;
    _3958 = MAKE_SEQ(_1);
    _0 = _3958;
    _3958 = machine(51, _3958);
    DeRefDS(_0);
    DeRef(_lib);
    DeRef(_routine_name);
    DeRefDS(_arg_types);
    DeRef(_return_type);
    return _3958;
    ;
}


int _17call_back(int _id)
{
    int _3960 = 0;
    int _0, _1, _2;
    

    //     return machine_func(M_CALL_BACK, id)
    _3960 = machine(52, _id);
    DeRef(_id);
    return _3960;
    ;
}


int _17free_console()
{
    int _0, _1, _2;
    

    //     machine_proc(M_FREE_CONSOLE, 0)
    machine(54, 0);

    // end procedure
    return 0;
    ;
}


