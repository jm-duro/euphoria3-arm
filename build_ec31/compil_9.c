// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _18opGETC()
{
    int _9997 = 0;
    int _9995 = 0;
    int _0, _1, _2;
    

    //     CSaveStr("_0", Code[pc+2], Code[pc+1], 0, 0)
    _9995 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9995 = (int)*(((s1_ptr)_2)->base + _9995);
    Ref(_9995);
    _9997 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9997 = (int)*(((s1_ptr)_2)->base + _9997);
    Ref(_9997);
    RefDS(_5774);
    Ref(_9995);
    Ref(_9997);
    _18CSaveStr(_5774, _9995, _9997, 0, 0);

    //     c_stmt("if (@ != last_r_file_no) {\n", Code[pc+1])
    DeRef(_9997);
    _9997 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9997 = (int)*(((s1_ptr)_2)->base + _9997);
    Ref(_9997);
    RefDS(_9999);
    Ref(_9997);
    _16c_stmt(_9999, _9997);

    //     c_stmt("last_r_file_ptr = which_file(@, EF_READ);\n", Code[pc+1])
    DeRef(_9997);
    _9997 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9997 = (int)*(((s1_ptr)_2)->base + _9997);
    Ref(_9997);
    RefDS(_10002);
    Ref(_9997);
    _16c_stmt(_10002, _9997);

    //     if TypeIsNot(Code[pc+1], TYPE_INTEGER) then 
    DeRef(_9997);
    _9997 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9997 = (int)*(((s1_ptr)_2)->base + _9997);
    Ref(_9997);
    Ref(_9997);
    _0 = _9997;
    _9997 = _16TypeIsNot(_9997, 1);
    DeRef(_0);
    if (_9997 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_9997) && DBL_PTR(_9997)->dbl == 0.0)
            goto L1;
    }

    // 	c_stmt("if (IS_ATOM_INT(@))\n", Code[pc+1])
    DeRef(_9997);
    _9997 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9997 = (int)*(((s1_ptr)_2)->base + _9997);
    Ref(_9997);
    RefDS(_5783);
    Ref(_9997);
    _16c_stmt(_5783, _9997);
L1:

    //     c_stmt("last_r_file_no = @;\n", Code[pc+1])
    DeRef(_9997);
    _9997 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9997 = (int)*(((s1_ptr)_2)->base + _9997);
    Ref(_9997);
    RefDS(_10010);
    Ref(_9997);
    _16c_stmt(_10010, _9997);

    //     if TypeIsNot(Code[pc+1], TYPE_INTEGER) then
    DeRef(_9997);
    _9997 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9997 = (int)*(((s1_ptr)_2)->base + _9997);
    Ref(_9997);
    Ref(_9997);
    _0 = _9997;
    _9997 = _16TypeIsNot(_9997, 1);
    DeRef(_0);
    if (_9997 == 0) {
        goto L2;
    }
    else {
        if (!IS_ATOM_INT(_9997) && DBL_PTR(_9997)->dbl == 0.0)
            goto L2;
    }

    // 	c_stmt0("else\n")
    RefDS(_5799);
    _16c_stmt0(_5799);

    // 	c_stmt0("last_r_file_no = NOVALUE;\n")
    RefDS(_10016);
    _16c_stmt0(_10016);
L2:

    //     c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    //     if not EDOS then
    if (_4EDOS != 0)
        goto L3;

    // 	c_stmt0("if (last_r_file_ptr == xstdin) {\n")
    RefDS(_10018);
    _16c_stmt0(_10018);

    // 	if EWINDOWS then
    if (_4EWINDOWS == 0)
        goto L4;

    // 	    c_stmt0("show_console();\n")
    RefDS(_10019);
    _16c_stmt0(_10019);
L4:

    // 	c_stmt0("if (in_from_keyb) {\n")
    RefDS(_10020);
    _16c_stmt0(_10020);

    // 	if ELINUX then
    if (_4ELINUX == 0)
        goto L5;

    // 	    if EGPM then

    // 		c_stmt("@ = getc(xstdin);\n", Code[pc+2])   -- echo the character
    DeRef(_9997);
    _9997 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9997 = (int)*(((s1_ptr)_2)->base + _9997);
    Ref(_9997);
    RefDS(_10024);
    Ref(_9997);
    _16c_stmt(_10024, _9997);
L6:
    goto L7;
L5:

    // 	    c_stmt("@ = wingetch();\n", Code[pc+2])
    DeRef(_9997);
    _9997 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9997 = (int)*(((s1_ptr)_2)->base + _9997);
    Ref(_9997);
    RefDS(_10027);
    Ref(_9997);
    _16c_stmt(_10027, _9997);
L7:

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt0("else\n")
    RefDS(_5799);
    _16c_stmt0(_5799);

    // 	c_stmt("@ = getc(last_r_file_ptr);\n", Code[pc+2])
    DeRef(_9997);
    _9997 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9997 = (int)*(((s1_ptr)_2)->base + _9997);
    Ref(_9997);
    RefDS(_10030);
    Ref(_9997);
    _16c_stmt(_10030, _9997);

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt0("else\n")
    RefDS(_5799);
    _16c_stmt0(_5799);
L3:

    //     c_stmt("@ = getc(last_r_file_ptr);\n", Code[pc+2])
    DeRef(_9997);
    _9997 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9997 = (int)*(((s1_ptr)_2)->base + _9997);
    Ref(_9997);
    RefDS(_10030);
    Ref(_9997);
    _16c_stmt(_10030, _9997);

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     target = {-1, 255}
    DeRef(_18target);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -1;
    ((int *)_2)[2] = 255;
    _18target = MAKE_SEQ(_1);

    //     SetBBType(Code[pc+2], TYPE_INTEGER, target, TYPE_OBJECT)
    DeRef(_9997);
    _9997 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9997 = (int)*(((s1_ptr)_2)->base + _9997);
    Ref(_9997);
    Ref(_9997);
    RefDS(_18target);
    _16SetBBType(_9997, 1, _18target, 16);

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    DeRef(_9997);
    DeRef(_9995);
    return 0;
    ;
}


int _18opGETS()
{
    int _10039 = 0;
    int _10041 = 0;
    int _0, _1, _2;
    

    //     CSaveStr("_0", Code[pc+2], Code[pc+1], 0, 0)
    _10039 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _10039 = (int)*(((s1_ptr)_2)->base + _10039);
    Ref(_10039);
    _10041 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10041 = (int)*(((s1_ptr)_2)->base + _10041);
    Ref(_10041);
    RefDS(_5774);
    Ref(_10039);
    Ref(_10041);
    _18CSaveStr(_5774, _10039, _10041, 0, 0);

    //     c_stmt("@ = EGets(@);\n", {Code[pc+2], Code[pc+1]})   
    DeRef(_10041);
    _10041 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _10041 = (int)*(((s1_ptr)_2)->base + _10041);
    Ref(_10041);
    DeRef(_10039);
    _10039 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10039 = (int)*(((s1_ptr)_2)->base + _10039);
    Ref(_10039);
    _0 = _10039;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _10041;
    Ref(_10041);
    ((int *)_2)[2] = _10039;
    Ref(_10039);
    _10039 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_10043);
    RefDS(_10039);
    _16c_stmt(_10043, _10039);

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     SetBBType(Code[pc+2], TYPE_OBJECT, novalue, TYPE_INTEGER) -- N.B.
    DeRefDS(_10039);
    _10039 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _10039 = (int)*(((s1_ptr)_2)->base + _10039);
    Ref(_10039);
    Ref(_10039);
    RefDS(_9novalue);
    _16SetBBType(_10039, 16, _9novalue, 1);

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    DeRef(_10039);
    DeRef(_10041);
    return 0;
    ;
}


int _18opGET_KEY()
{
    int _10052 = 0;
    int _0, _1, _2;
    

    //     if not EDOS and EWINDOWS then
    _10052 = (_4EDOS == 0);
    if (_10052 == 0) {
        goto L1;
    }
L2:
    if (_4EWINDOWS == 0)
        goto L1;

    // 	c_stmt0("show_console();\n")
    RefDS(_10019);
    _16c_stmt0(_10019);
L1:

    //     CSaveStr("_0", Code[pc+1], 0, 0, 0)
    DeRef(_10052);
    _10052 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10052 = (int)*(((s1_ptr)_2)->base + _10052);
    Ref(_10052);
    RefDS(_5774);
    Ref(_10052);
    _18CSaveStr(_5774, _10052, 0, 0, 0);

    //     c_stmt("@ = get_key(0);\n", Code[pc+1])
    DeRef(_10052);
    _10052 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10052 = (int)*(((s1_ptr)_2)->base + _10052);
    Ref(_10052);
    RefDS(_10056);
    Ref(_10052);
    _16c_stmt(_10056, _10052);

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     target = {-1, 1000}
    DeRef(_18target);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -1;
    ((int *)_2)[2] = 1000;
    _18target = MAKE_SEQ(_1);

    //     SetBBType(Code[pc+1], TYPE_INTEGER, target, TYPE_OBJECT)
    DeRef(_10052);
    _10052 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10052 = (int)*(((s1_ptr)_2)->base + _10052);
    Ref(_10052);
    Ref(_10052);
    RefDS(_18target);
    _16SetBBType(_10052, 1, _18target, 16);

    //     pc += 2
    _18pc = _18pc + 2;

    // end procedure
    DeRef(_10052);
    return 0;
    ;
}


int _18opCLEAR_SCREEN()
{
    int _0, _1, _2;
    

    //     c_stmt0("ClearScreen();\n")
    RefDS(_10063);
    _16c_stmt0(_10063);

    //     pc += 1
    _18pc = _18pc + 1;

    // end procedure
    return 0;
    ;
}


int _18opPUTS()
{
    int _10068 = 0;
    int _10066 = 0;
    int _0, _1, _2;
    

    //     c_stmt("EPuts(@, @);\n", {Code[pc+1], Code[pc+2]})
    _10066 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10066 = (int)*(((s1_ptr)_2)->base + _10066);
    Ref(_10066);
    _10068 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _10068 = (int)*(((s1_ptr)_2)->base + _10068);
    Ref(_10068);
    _0 = _10068;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _10066;
    Ref(_10066);
    ((int *)_2)[2] = _10068;
    Ref(_10068);
    _10068 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_10065);
    RefDS(_10068);
    _16c_stmt(_10065, _10068);

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    DeRefDS(_10068);
    DeRef(_10066);
    return 0;
    ;
}


int _18opPRINT()
{
    int _10072 = 0;
    int _10077 = 0;
    int _0, _1, _2;
    

    //     if Code[pc] = QPRINT then
    _2 = (int)SEQ_PTR(_4Code);
    _10072 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_10072);
    if (binary_op_a(NOTEQ, _10072, 36))
        goto L1;

    // 	c_stmt("StdPrint(@, @, 1);\n", {Code[pc+1], Code[pc+2]})
    DeRef(_10072);
    _10072 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10072 = (int)*(((s1_ptr)_2)->base + _10072);
    Ref(_10072);
    _10077 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _10077 = (int)*(((s1_ptr)_2)->base + _10077);
    Ref(_10077);
    _0 = _10077;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _10072;
    Ref(_10072);
    ((int *)_2)[2] = _10077;
    Ref(_10077);
    _10077 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_10074);
    RefDS(_10077);
    _16c_stmt(_10074, _10077);
    goto L2;
L1:

    // 	c_stmt("StdPrint(@, @, 0);\n", {Code[pc+1], Code[pc+2]})
    DeRef(_10077);
    _10077 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10077 = (int)*(((s1_ptr)_2)->base + _10077);
    Ref(_10077);
    DeRef(_10072);
    _10072 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _10072 = (int)*(((s1_ptr)_2)->base + _10072);
    Ref(_10072);
    _0 = _10072;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _10077;
    Ref(_10077);
    ((int *)_2)[2] = _10072;
    Ref(_10072);
    _10072 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_10080);
    RefDS(_10072);
    _16c_stmt(_10080, _10072);
L2:

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    DeRef(_10072);
    DeRef(_10077);
    return 0;
    ;
}


int _18opPRINTF()
{
    int _10092 = 0;
    int _10090 = 0;
    int _10088 = 0;
    int _0, _1, _2;
    

    //     c_stmt("EPrintf(@, @, @);\n", {Code[pc+1], Code[pc+2], Code[pc+3]})
    _10088 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10088 = (int)*(((s1_ptr)_2)->base + _10088);
    Ref(_10088);
    _10090 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _10090 = (int)*(((s1_ptr)_2)->base + _10090);
    Ref(_10090);
    _10092 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _10092 = (int)*(((s1_ptr)_2)->base + _10092);
    Ref(_10092);
    _0 = _10092;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_10088);
    *((int *)(_2+4)) = _10088;
    Ref(_10090);
    *((int *)(_2+8)) = _10090;
    Ref(_10092);
    *((int *)(_2+12)) = _10092;
    _10092 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_10087);
    RefDS(_10092);
    _16c_stmt(_10087, _10092);

    //     pc += 4
    _18pc = _18pc + 4;

    // end procedure
    DeRefDS(_10092);
    DeRef(_10090);
    DeRef(_10088);
    return 0;
    ;
}


int _18opSPRINTF()
{
    int _10112 = 0;
    int _10098 = 0;
    int _10100 = 0;
    int _10102 = 0;
    int _0, _1, _2;
    

    //     CSaveStr("_0", Code[pc+3], Code[pc+1], Code[pc+2], 0)
    _10098 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _10098 = (int)*(((s1_ptr)_2)->base + _10098);
    Ref(_10098);
    _10100 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10100 = (int)*(((s1_ptr)_2)->base + _10100);
    Ref(_10100);
    _10102 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _10102 = (int)*(((s1_ptr)_2)->base + _10102);
    Ref(_10102);
    RefDS(_5774);
    Ref(_10098);
    Ref(_10100);
    Ref(_10102);
    _18CSaveStr(_5774, _10098, _10100, _10102, 0);

    //     c_stmt("@ = EPrintf(" & sprintf("%d", DOING_SPRINTF) & ", @, @);\n", 
    DeRef(_10102);
    _10102 = EPrintf(-9999999, _9018, -9999999);
    {
        int concat_list[3];

        concat_list[0] = _10106;
        concat_list[1] = _10102;
        concat_list[2] = _10104;
        Concat_N((object_ptr)&_10102, concat_list, 3);
    }
    DeRef(_10100);
    _10100 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _10100 = (int)*(((s1_ptr)_2)->base + _10100);
    Ref(_10100);
    DeRef(_10098);
    _10098 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10098 = (int)*(((s1_ptr)_2)->base + _10098);
    Ref(_10098);
    _10112 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _10112 = (int)*(((s1_ptr)_2)->base + _10112);
    Ref(_10112);
    _0 = _10112;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_10100);
    *((int *)(_2+4)) = _10100;
    Ref(_10098);
    *((int *)(_2+8)) = _10098;
    Ref(_10112);
    *((int *)(_2+12)) = _10112;
    _10112 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_10102);
    RefDS(_10112);
    _16c_stmt(_10102, _10112);

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     SetBBType(Code[pc+3], TYPE_SEQUENCE, novalue, TYPE_INTEGER)
    DeRefDS(_10112);
    _10112 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _10112 = (int)*(((s1_ptr)_2)->base + _10112);
    Ref(_10112);
    Ref(_10112);
    RefDS(_9novalue);
    _16SetBBType(_10112, 8, _9novalue, 1);

    //     pc += 4
    _18pc = _18pc + 4;

    // end procedure
    DeRefDSi(_10102);
    DeRef(_10112);
    DeRef(_10098);
    DeRef(_10100);
    return 0;
    ;
}


int _18opCOMMAND_LINE()
{
    int _10118 = 0;
    int _0, _1, _2;
    

    //     CSaveStr("_0", Code[pc+1], 0, 0, 0)
    _10118 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10118 = (int)*(((s1_ptr)_2)->base + _10118);
    Ref(_10118);
    RefDS(_5774);
    Ref(_10118);
    _18CSaveStr(_5774, _10118, 0, 0, 0);

    //     c_stmt("@ = Command_Line();\n" , Code[pc+1])
    DeRef(_10118);
    _10118 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10118 = (int)*(((s1_ptr)_2)->base + _10118);
    Ref(_10118);
    RefDS(_10120);
    Ref(_10118);
    _16c_stmt(_10120, _10118);

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     SetBBType(Code[pc+1], TYPE_SEQUENCE, novalue, TYPE_SEQUENCE)
    DeRef(_10118);
    _10118 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10118 = (int)*(((s1_ptr)_2)->base + _10118);
    Ref(_10118);
    Ref(_10118);
    RefDS(_9novalue);
    _16SetBBType(_10118, 8, _9novalue, 8);

    //     pc += 2
    _18pc = _18pc + 2;

    // end procedure
    DeRef(_10118);
    return 0;
    ;
}


int _18opGETENV()
{
    int _10131 = 0;
    int _10126 = 0;
    int _0, _1, _2;
    

    //     CSaveStr("_0", Code[pc+2], 0, 0, 0)
    _10126 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _10126 = (int)*(((s1_ptr)_2)->base + _10126);
    Ref(_10126);
    RefDS(_5774);
    Ref(_10126);
    _18CSaveStr(_5774, _10126, 0, 0, 0);

    //     c_stmt("@ = EGetEnv(@);\n", {Code[pc+2], Code[pc+1]})
    DeRef(_10126);
    _10126 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _10126 = (int)*(((s1_ptr)_2)->base + _10126);
    Ref(_10126);
    _10131 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10131 = (int)*(((s1_ptr)_2)->base + _10131);
    Ref(_10131);
    _0 = _10131;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _10126;
    Ref(_10126);
    ((int *)_2)[2] = _10131;
    Ref(_10131);
    _10131 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_10128);
    RefDS(_10131);
    _16c_stmt(_10128, _10131);

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     SetBBType(Code[pc+2], TYPE_OBJECT, novalue, TYPE_INTEGER) -- N.B.
    DeRefDS(_10131);
    _10131 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _10131 = (int)*(((s1_ptr)_2)->base + _10131);
    Ref(_10131);
    Ref(_10131);
    RefDS(_9novalue);
    _16SetBBType(_10131, 16, _9novalue, 1);

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    DeRef(_10131);
    DeRef(_10126);
    return 0;
    ;
}


int _18opMACHINE_FUNC()
{
    int _10158 = 0;
    int _10141 = 0;
    int _10139 = 0;
    int _10137 = 0;
    int _0, _1, _2;
    

    //     CSaveStr("_0", Code[pc+3], Code[pc+1], Code[pc+2], 0)
    _10137 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _10137 = (int)*(((s1_ptr)_2)->base + _10137);
    Ref(_10137);
    _10139 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10139 = (int)*(((s1_ptr)_2)->base + _10139);
    Ref(_10139);
    _10141 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _10141 = (int)*(((s1_ptr)_2)->base + _10141);
    Ref(_10141);
    RefDS(_5774);
    Ref(_10137);
    Ref(_10139);
    Ref(_10141);
    _18CSaveStr(_5774, _10137, _10139, _10141, 0);

    //     c_stmt("@ = machine(@, @);\n", {Code[pc+3], Code[pc+1], Code[pc+2]})
    DeRef(_10141);
    _10141 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _10141 = (int)*(((s1_ptr)_2)->base + _10141);
    Ref(_10141);
    DeRef(_10139);
    _10139 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10139 = (int)*(((s1_ptr)_2)->base + _10139);
    Ref(_10139);
    DeRef(_10137);
    _10137 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _10137 = (int)*(((s1_ptr)_2)->base + _10137);
    Ref(_10137);
    _0 = _10137;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_10141);
    *((int *)(_2+4)) = _10141;
    Ref(_10139);
    *((int *)(_2+8)) = _10139;
    Ref(_10137);
    *((int *)(_2+12)) = _10137;
    _10137 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_10143);
    RefDS(_10137);
    _16c_stmt(_10143, _10137);

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     target = machine_func_type(Code[pc+1])
    DeRefDS(_10137);
    _10137 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10137 = (int)*(((s1_ptr)_2)->base + _10137);
    Ref(_10137);
    Ref(_10137);
    _0 = _18machine_func_type(_10137);
    DeRef(_18target);
    _18target = _0;

    //     SetBBType(Code[pc+3], target[1], target[2], 
    DeRef(_10137);
    _10137 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _10137 = (int)*(((s1_ptr)_2)->base + _10137);
    Ref(_10137);
    DeRef(_10139);
    _2 = (int)SEQ_PTR(_18target);
    _10139 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_10139);
    DeRef(_10141);
    _2 = (int)SEQ_PTR(_18target);
    _10141 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_10141);
    _10158 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10158 = (int)*(((s1_ptr)_2)->base + _10158);
    Ref(_10158);
    Ref(_10158);
    _0 = _10158;
    _10158 = _18machine_func_elem_type(_10158);
    DeRef(_0);
    Ref(_10137);
    Ref(_10139);
    Ref(_10141);
    _16SetBBType(_10137, _10139, _10141, _10158);

    //     pc += 4
    _18pc = _18pc + 4;

    // end procedure
    DeRef(_10141);
    DeRef(_10139);
    DeRef(_10137);
    return 0;
    ;
}


int _18opMACHINE_PROC()
{
    int _10165 = 0;
    int _10163 = 0;
    int _0, _1, _2;
    

    //     c_stmt("machine(@, @);\n", {Code[pc+1], Code[pc+2]})
    _10163 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10163 = (int)*(((s1_ptr)_2)->base + _10163);
    Ref(_10163);
    _10165 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _10165 = (int)*(((s1_ptr)_2)->base + _10165);
    Ref(_10165);
    _0 = _10165;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _10163;
    Ref(_10163);
    ((int *)_2)[2] = _10165;
    Ref(_10165);
    _10165 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_10162);
    RefDS(_10165);
    _16c_stmt(_10162, _10165);

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    DeRefDS(_10165);
    DeRef(_10163);
    return 0;
    ;
}


int _18opC_FUNC()
{
    int _10171 = 0;
    int _10169 = 0;
    int _10173 = 0;
    int _0, _1, _2, _3;
    

    //     CSaveStr("_0", Code[pc+4], Code[pc+2], Code[pc+1], 0)
    _10169 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _10169 = (int)*(((s1_ptr)_2)->base + _10169);
    Ref(_10169);
    _10171 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _10171 = (int)*(((s1_ptr)_2)->base + _10171);
    Ref(_10171);
    _10173 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10173 = (int)*(((s1_ptr)_2)->base + _10173);
    Ref(_10173);
    RefDS(_5774);
    Ref(_10169);
    Ref(_10171);
    Ref(_10173);
    _18CSaveStr(_5774, _10169, _10171, _10173, 0);

    //     c_stmt("@ = call_c(1, @, @);\n", {Code[pc+4], Code[pc+1], Code[pc+2]})
    DeRef(_10173);
    _10173 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _10173 = (int)*(((s1_ptr)_2)->base + _10173);
    Ref(_10173);
    DeRef(_10171);
    _10171 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10171 = (int)*(((s1_ptr)_2)->base + _10171);
    Ref(_10171);
    DeRef(_10169);
    _10169 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _10169 = (int)*(((s1_ptr)_2)->base + _10169);
    Ref(_10169);
    _0 = _10169;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_10173);
    *((int *)(_2+4)) = _10173;
    Ref(_10171);
    *((int *)(_2+8)) = _10171;
    Ref(_10169);
    *((int *)(_2+12)) = _10169;
    _10169 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_10175);
    RefDS(_10169);
    _16c_stmt(_10175, _10169);

    //     SymTab[Code[pc+4]][S_ONE_REF] = FALSE  
    DeRefDS(_10169);
    _10169 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _10169 = (int)*(((s1_ptr)_2)->base + _10169);
    Ref(_10169);
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_10169))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_10169)->dbl));
    else
        _3 = (int)(_10169 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 32);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     NewBB(1, E_ALL_EFFECT, 0) -- Windows call-back to Euphoria routine could occur
    _16NewBB(1, 1073741823, 0);

    //     SetBBType(Code[pc+4], TYPE_OBJECT, -- might be call to Euphoria routine
    DeRef(_10171);
    _10171 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _10171 = (int)*(((s1_ptr)_2)->base + _10171);
    Ref(_10171);
    Ref(_10171);
    RefDS(_9novalue);
    _16SetBBType(_10171, 16, _9novalue, 16);

    //     pc += 5
    _18pc = _18pc + 5;

    // end procedure
    DeRef(_10171);
    DeRef(_10169);
    DeRef(_10173);
    return 0;
    ;
}


int _18opC_PROC()
{
    int _10194 = 0;
    int _10190 = 0;
    int _0, _1, _2;
    

    //     if not EDOS then             
    if (_4EDOS != 0)
        goto L1;

    // 	c_stmt("call_c(0, @, @);\n", {Code[pc+1], Code[pc+2]})
    _10190 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10190 = (int)*(((s1_ptr)_2)->base + _10190);
    Ref(_10190);
    _10194 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _10194 = (int)*(((s1_ptr)_2)->base + _10194);
    Ref(_10194);
    _0 = _10194;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _10190;
    Ref(_10190);
    ((int *)_2)[2] = _10194;
    Ref(_10194);
    _10194 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_10191);
    RefDS(_10194);
    _16c_stmt(_10191, _10194);
L1:

    //     NewBB(1, E_ALL_EFFECT, 0) -- Windows call-back to Euphoria routine could occur
    _16NewBB(1, 1073741823, 0);

    //     pc += 4
    _18pc = _18pc + 4;

    // end procedure
    DeRef(_10194);
    DeRef(_10190);
    return 0;
    ;
}


int _18opTRACE()
{
    int _10198 = 0;
    int _0, _1, _2;
    

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then
    _10198 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10198 = (int)*(((s1_ptr)_2)->base + _10198);
    Ref(_10198);
    Ref(_10198);
    RefDS(_5781);
    _0 = _10198;
    _10198 = _16TypeIs(_10198, _5781);
    DeRef(_0);
    if (_10198 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_10198) && DBL_PTR(_10198)->dbl == 0.0)
            goto L1;
    }

    // 	c_stmt("if (IS_ATOM_INT(@))\n", Code[pc+1])
    DeRef(_10198);
    _10198 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10198 = (int)*(((s1_ptr)_2)->base + _10198);
    Ref(_10198);
    RefDS(_5783);
    Ref(_10198);
    _16c_stmt(_5783, _10198);
L1:

    //     if TypeIs(Code[pc+1], {TYPE_INTEGER, TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_10198);
    _10198 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10198 = (int)*(((s1_ptr)_2)->base + _10198);
    Ref(_10198);
    Ref(_10198);
    RefDS(_6197);
    _0 = _10198;
    _10198 = _16TypeIs(_10198, _6197);
    DeRef(_0);
    if (_10198 == 0) {
        goto L2;
    }
    else {
        if (!IS_ATOM_INT(_10198) && DBL_PTR(_10198)->dbl == 0.0)
            goto L2;
    }

    // 	c_stmt("TraceOn = @;\n", Code[pc+1])
    DeRef(_10198);
    _10198 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10198 = (int)*(((s1_ptr)_2)->base + _10198);
    Ref(_10198);
    RefDS(_10206);
    Ref(_10198);
    _16c_stmt(_10206, _10198);
L2:

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_10198);
    _10198 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10198 = (int)*(((s1_ptr)_2)->base + _10198);
    Ref(_10198);
    Ref(_10198);
    RefDS(_5781);
    _0 = _10198;
    _10198 = _16TypeIs(_10198, _5781);
    DeRef(_0);
    if (_10198 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_10198) && DBL_PTR(_10198)->dbl == 0.0)
            goto L3;
    }

    // 	c_stmt0("else\n")
    RefDS(_5799);
    _16c_stmt0(_5799);
L3:

    //     if TypeIsNot(Code[pc+1], TYPE_INTEGER) then
    DeRef(_10198);
    _10198 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10198 = (int)*(((s1_ptr)_2)->base + _10198);
    Ref(_10198);
    Ref(_10198);
    _0 = _10198;
    _10198 = _16TypeIsNot(_10198, 1);
    DeRef(_0);
    if (_10198 == 0) {
        goto L4;
    }
    else {
        if (!IS_ATOM_INT(_10198) && DBL_PTR(_10198)->dbl == 0.0)
            goto L4;
    }

    // 	c_stmt("TraceOn = DBL_PTR(@)->dbl != 0.0;\n", Code[pc+1])
    DeRef(_10198);
    _10198 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10198 = (int)*(((s1_ptr)_2)->base + _10198);
    Ref(_10198);
    RefDS(_10215);
    Ref(_10198);
    _16c_stmt(_10215, _10198);
L4:

    //     pc += 2
    _18pc = _18pc + 2;

    // end procedure
    DeRef(_10198);
    return 0;
    ;
}


int _18opPROFILE()
{
    int _0, _1, _2;
    

    //     pc += 2
    _18pc = _18pc + 2;

    // end procedure
    return 0;
    ;
}


int _18opUPDATE_GLOBALS()
{
    int _0, _1, _2;
    

    //     pc += 1
    _18pc = _18pc + 1;

    // end procedure
    return 0;
    ;
}


int _18dll_tasking()
{
    int _0, _1, _2;
    

    //     if dll_option then
    if (_16dll_option == 0)
        goto L1;

    // 	CompileErr("Multitasking operations are not supported in a .dll or .so")
    RefDS(_10221);
    _6CompileErr(_10221);
L1:

    // end procedure
    return 0;
    ;
}


int _18opTASK_CREATE()
{
    int _10222 = 0;
    int _10224 = 0;
    int _10226 = 0;
    int _0, _1, _2;
    

    //     dll_tasking()
    _18dll_tasking();

    //     CSaveStr("_0", Code[pc+3], Code[pc+1], Code[pc+2], 0)
    _10222 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _10222 = (int)*(((s1_ptr)_2)->base + _10222);
    Ref(_10222);
    _10224 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10224 = (int)*(((s1_ptr)_2)->base + _10224);
    Ref(_10224);
    _10226 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _10226 = (int)*(((s1_ptr)_2)->base + _10226);
    Ref(_10226);
    RefDS(_5774);
    Ref(_10222);
    Ref(_10224);
    Ref(_10226);
    _18CSaveStr(_5774, _10222, _10224, _10226, 0);

    //     c_stmt("@ = task_create(@, @);\n", {Code[pc+3], Code[pc+1], Code[pc+2]})
    DeRef(_10226);
    _10226 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _10226 = (int)*(((s1_ptr)_2)->base + _10226);
    Ref(_10226);
    DeRef(_10224);
    _10224 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10224 = (int)*(((s1_ptr)_2)->base + _10224);
    Ref(_10224);
    DeRef(_10222);
    _10222 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _10222 = (int)*(((s1_ptr)_2)->base + _10222);
    Ref(_10222);
    _0 = _10222;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_10226);
    *((int *)(_2+4)) = _10226;
    Ref(_10224);
    *((int *)(_2+8)) = _10224;
    Ref(_10222);
    *((int *)(_2+12)) = _10222;
    _10222 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_10228);
    RefDS(_10222);
    _16c_stmt(_10228, _10222);

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     SetBBType(Code[pc+3], TYPE_DOUBLE, novalue, TYPE_OBJECT) -- always TYPE_DOUBLE
    DeRefDS(_10222);
    _10222 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _10222 = (int)*(((s1_ptr)_2)->base + _10222);
    Ref(_10222);
    Ref(_10222);
    RefDS(_9novalue);
    _16SetBBType(_10222, 2, _9novalue, 16);

    //     tasks_created = TRUE
    _18tasks_created = 1;

    //     pc += 4 
    _18pc = _18pc + 4;

    // end procedure
    DeRef(_10222);
    DeRef(_10224);
    DeRef(_10226);
    return 0;
    ;
}


int _18opTASK_SCHEDULE()
{
    int _10242 = 0;
    int _10240 = 0;
    int _0, _1, _2;
    

    //     dll_tasking()
    _18dll_tasking();

    //     c_stmt("task_schedule(@, @);\n", {Code[pc+1], Code[pc+2]})
    _10240 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10240 = (int)*(((s1_ptr)_2)->base + _10240);
    Ref(_10240);
    _10242 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _10242 = (int)*(((s1_ptr)_2)->base + _10242);
    Ref(_10242);
    _0 = _10242;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _10240;
    Ref(_10240);
    ((int *)_2)[2] = _10242;
    Ref(_10242);
    _10242 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_10239);
    RefDS(_10242);
    _16c_stmt(_10239, _10242);

    //     pc += 3 
    _18pc = _18pc + 3;

    // end procedure
    DeRefDS(_10242);
    DeRef(_10240);
    return 0;
    ;
}


int _18opTASK_YIELD()
{
    int _0, _1, _2;
    

    //     dll_tasking()
    _18dll_tasking();

    //     c_stmt0("task_yield();\n")
    RefDS(_10246);
    _16c_stmt0(_10246);

    //     pc += 1 
    _18pc = _18pc + 1;

    // end procedure
    return 0;
    ;
}


int _18opTASK_SELF()
{
    int _10248 = 0;
    int _0, _1, _2;
    

    //     dll_tasking()
    _18dll_tasking();

    //     CDeRef(Code[pc+1]) -- Code[pc+1] not used in next expression
    _10248 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10248 = (int)*(((s1_ptr)_2)->base + _10248);
    Ref(_10248);
    Ref(_10248);
    _18CDeRef(_10248);

    //     c_stmt("@ = NewDouble(tcb[current_task].tid);\n", {Code[pc+1]})
    DeRef(_10248);
    _10248 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10248 = (int)*(((s1_ptr)_2)->base + _10248);
    Ref(_10248);
    _0 = _10248;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_10248);
    *((int *)(_2+4)) = _10248;
    _10248 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_10250);
    RefDS(_10248);
    _16c_stmt(_10250, _10248);

    //     SetBBType(Code[pc+1], TYPE_DOUBLE, novalue, TYPE_OBJECT) -- always TYPE_DOUBLE
    DeRefDS(_10248);
    _10248 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10248 = (int)*(((s1_ptr)_2)->base + _10248);
    Ref(_10248);
    Ref(_10248);
    RefDS(_9novalue);
    _16SetBBType(_10248, 2, _9novalue, 16);

    //     pc += 2 
    _18pc = _18pc + 2;

    // end procedure
    DeRef(_10248);
    return 0;
    ;
}


int _18opTASK_SUSPEND()
{
    int _10258 = 0;
    int _0, _1, _2;
    

    //     dll_tasking()
    _18dll_tasking();

    //     c_stmt("task_suspend(@);\n", {Code[pc+1]})
    _10258 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10258 = (int)*(((s1_ptr)_2)->base + _10258);
    Ref(_10258);
    _0 = _10258;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_10258);
    *((int *)(_2+4)) = _10258;
    _10258 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_10257);
    RefDS(_10258);
    _16c_stmt(_10257, _10258);

    //     pc += 2 
    _18pc = _18pc + 2;

    // end procedure
    DeRefDS(_10258);
    return 0;
    ;
}


int _18opTASK_LIST()
{
    int _10262 = 0;
    int _0, _1, _2;
    

    //     dll_tasking()
    _18dll_tasking();

    //     CDeRef(Code[pc+1]) -- Code[pc+1] not used in next expression
    _10262 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10262 = (int)*(((s1_ptr)_2)->base + _10262);
    Ref(_10262);
    Ref(_10262);
    _18CDeRef(_10262);

    //     c_stmt("@ = task_list();\n", {Code[pc+1]})
    DeRef(_10262);
    _10262 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10262 = (int)*(((s1_ptr)_2)->base + _10262);
    Ref(_10262);
    _0 = _10262;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_10262);
    *((int *)(_2+4)) = _10262;
    _10262 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_10264);
    RefDS(_10262);
    _16c_stmt(_10264, _10262);

    //     SetBBType(Code[pc+1], TYPE_SEQUENCE, novalue, TYPE_DOUBLE)
    DeRefDS(_10262);
    _10262 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10262 = (int)*(((s1_ptr)_2)->base + _10262);
    Ref(_10262);
    Ref(_10262);
    RefDS(_9novalue);
    _16SetBBType(_10262, 8, _9novalue, 2);

    //     pc += 2 
    _18pc = _18pc + 2;

    // end procedure
    DeRef(_10262);
    return 0;
    ;
}


int _18opTASK_STATUS()
{
    int _10273 = 0;
    int _10271 = 0;
    int _0, _1, _2;
    

    //     dll_tasking()
    _18dll_tasking();

    //     CSaveStr("_0", Code[pc+2], Code[pc+1], 0, 0)
    _10271 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _10271 = (int)*(((s1_ptr)_2)->base + _10271);
    Ref(_10271);
    _10273 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10273 = (int)*(((s1_ptr)_2)->base + _10273);
    Ref(_10273);
    RefDS(_5774);
    Ref(_10271);
    Ref(_10273);
    _18CSaveStr(_5774, _10271, _10273, 0, 0);

    //     c_stmt("@ = task_status(@);\n", {Code[pc+2], Code[pc+1]})
    DeRef(_10273);
    _10273 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _10273 = (int)*(((s1_ptr)_2)->base + _10273);
    Ref(_10273);
    DeRef(_10271);
    _10271 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _10271 = (int)*(((s1_ptr)_2)->base + _10271);
    Ref(_10271);
    _0 = _10271;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _10273;
    Ref(_10273);
    ((int *)_2)[2] = _10271;
    Ref(_10271);
    _10271 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_10275);
    RefDS(_10271);
    _16c_stmt(_10275, _10271);

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     SetBBType(Code[pc+2], TYPE_INTEGER, {-1,+1}, TYPE_OBJECT)
    DeRefDS(_10271);
    _10271 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _10271 = (int)*(((s1_ptr)_2)->base + _10271);
    Ref(_10271);
    DeRef(_10273);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -1;
    ((int *)_2)[2] = 1;
    _10273 = MAKE_SEQ(_1);
    Ref(_10271);
    RefDS(_10273);
    _16SetBBType(_10271, 1, _10273, 16);

    //     pc += 3 
    _18pc = _18pc + 3;

    // end procedure
    DeRefDSi(_10273);
    DeRef(_10271);
    return 0;
    ;
}


int _18opTASK_CLOCK_STOP()
{
    int _0, _1, _2;
    

    //     dll_tasking()
    _18dll_tasking();

    //     c_stmt0("task_clock_stop();\n")
    RefDS(_10285);
    _16c_stmt0(_10285);

    //     pc += 1 
    _18pc = _18pc + 1;

    // end procedure
    return 0;
    ;
}


int _18opTASK_CLOCK_START()
{
    int _0, _1, _2;
    

    //     dll_tasking()
    _18dll_tasking();

    //     c_stmt0("task_clock_start();\n")
    RefDS(_10287);
    _16c_stmt0(_10287);

    //     pc += 1
    _18pc = _18pc + 1;

    // end procedure
    return 0;
    ;
}


int _18init_opcodes()
{
    int _name = 0;
    int _10292 = 0;
    int _10289;
    int _0, _1, _2;
    

    //     operation = repeat(-1, length(opnames))
    _10289 = 179;
    DeRefi(_18operation);
    _18operation = Repeat(-1, 179);

    //     for i = 1 to length(opnames) do
    _10289 = 179;
    { int _i;
        _i = 1;
L1:
        if (_i > 179)
            goto L2;

        // 	name = opnames[i]
        DeRef(_name);
        _2 = (int)SEQ_PTR(_17opnames);
        _name = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_name);

        // 	if find(name, {"ASSIGN_OP_SUBS", "PASSIGN_OP_SUBS",
        _0 = _10292;
        _1 = NewS1(4);
        _2 = (int)((s1_ptr)_1)->base;
        RefDS(_5402);
        *((int *)(_2+4)) = _5402;
        RefDS(_5417);
        *((int *)(_2+8)) = _5417;
        RefDS(_10293);
        *((int *)(_2+12)) = _10293;
        RefDS(_10294);
        *((int *)(_2+16)) = _10294;
        _10292 = MAKE_SEQ(_1);
        DeRef(_0);
        _0 = _10292;
        _10292 = find(_name, _10292);
        DeRefDS(_0);
        if (_10292 == 0)
            goto L3;

        // 	    name = "RHS_SUBS"
        RefDS(_10297);
        DeRefDS(_name);
        _name = _10297;
        goto L4;
L3:

        // 	elsif equal(name, "NOPWHILE") then
        DeRef(_10292);
        if (_name == _5411)
            _10292 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_5411))
            _10292 = 0;
        else
            _10292 = (compare(_name, _5411) == 0);
        if (_10292 == 0)
            goto L5;

        // 	    name = "NOP1"
        RefDS(_5412);
        DeRefDS(_name);
        _name = _5412;
        goto L4;
L5:

        // 	elsif equal(name, "WHILE") then
        DeRef(_10292);
        if (_name == _10299)
            _10292 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_10299))
            _10292 = 0;
        else
            _10292 = (compare(_name, _10299) == 0);
        if (_10292 == 0)
            goto L6;

        // 	    name = "IF"
        RefDS(_10301);
        DeRefDS(_name);
        _name = _10301;
        goto L4;
L6:

        // 	elsif equal(name, "SEQUENCE_CHECK") then
        DeRef(_10292);
        if (_name == _10302)
            _10292 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_10302))
            _10292 = 0;
        else
            _10292 = (compare(_name, _10302) == 0);
        if (_10292 == 0)
            goto L7;

        // 	    name = "ATOM_CHECK" 
        RefDS(_10304);
        DeRefDS(_name);
        _name = _10304;
        goto L4;
L7:

        // 	elsif find(name, {"ASSIGN_SUBS_CHECK", "ASSIGN_SUBS_I", 
        _0 = _10292;
        _1 = NewS1(3);
        _2 = (int)((s1_ptr)_1)->base;
        RefDS(_10305);
        *((int *)(_2+4)) = _10305;
        RefDS(_10306);
        *((int *)(_2+8)) = _10306;
        RefDS(_5415);
        *((int *)(_2+12)) = _5415;
        _10292 = MAKE_SEQ(_1);
        DeRef(_0);
        _0 = _10292;
        _10292 = find(_name, _10292);
        DeRefDS(_0);
        if (_10292 == 0)
            goto L8;

        // 	    name = "ASSIGN_SUBS"
        RefDS(_10309);
        DeRefDS(_name);
        _name = _10309;
        goto L4;
L8:

        // 	elsif equal(name, "PLENGTH") then
        DeRef(_10292);
        if (_name == _5413)
            _10292 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_5413))
            _10292 = 0;
        else
            _10292 = (compare(_name, _5413) == 0);
        if (_10292 == 0)
            goto L9;

        // 	    name = "LENGTH"
        RefDS(_10311);
        DeRefDS(_name);
        _name = _10311;
        goto L4;
L9:

        // 	elsif find(name, {"ELSE", "ENDWHILE"}) then
        DeRef(_10292);
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _10312;
        RefDS(_10312);
        ((int *)_2)[2] = _10313;
        RefDS(_10313);
        _10292 = MAKE_SEQ(_1);
        _0 = _10292;
        _10292 = find(_name, _10292);
        DeRefDS(_0);
        if (_10292 == 0)
            goto LA;

        // 	    name = "EXIT"
        RefDS(_10316);
        DeRefDS(_name);
        _name = _10316;
        goto L4;
LA:

        // 	elsif equal(name, "PLUS1_I") then
        DeRef(_10292);
        if (_name == _10317)
            _10292 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_10317))
            _10292 = 0;
        else
            _10292 = (compare(_name, _10317) == 0);
        if (_10292 == 0)
            goto LB;

        // 	    name = "PLUS1"
        RefDS(_10319);
        DeRefDS(_name);
        _name = _10319;
        goto L4;
LB:

        // 	elsif equal(name, "PRIVATE_INIT_CHECK") then
        DeRef(_10292);
        if (_name == _10320)
            _10292 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_10320))
            _10292 = 0;
        else
            _10292 = (compare(_name, _10320) == 0);
        if (_10292 == 0)
            goto LC;

        // 	    name = "GLOBAL_INIT_CHECK"
        RefDS(_10322);
        DeRefDS(_name);
        _name = _10322;
        goto L4;
LC:

        // 	elsif find(name, {"LHS_SUBS1", "LHS_SUBS1_COPY"}) then
        DeRef(_10292);
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _5414;
        RefDS(_5414);
        ((int *)_2)[2] = _5419;
        RefDS(_5419);
        _10292 = MAKE_SEQ(_1);
        _0 = _10292;
        _10292 = find(_name, _10292);
        DeRefDS(_0);
        if (_10292 == 0)
            goto LD;

        // 	    name = "LHS_SUBS"
        RefDS(_10325);
        DeRefDS(_name);
        _name = _10325;
        goto L4;
LD:

        // 	elsif equal(name, "PASSIGN_OP_SLICE") then
        DeRef(_10292);
        if (_name == _5418)
            _10292 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_5418))
            _10292 = 0;
        else
            _10292 = (compare(_name, _5418) == 0);
        if (_10292 == 0)
            goto LE;

        // 	    name = "ASSIGN_OP_SLICE"
        RefDS(_5403);
        DeRefDS(_name);
        _name = _5403;
        goto L4;
LE:

        // 	elsif equal(name, "PASSIGN_SLICE") then
        DeRef(_10292);
        if (_name == _5416)
            _10292 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_5416))
            _10292 = 0;
        else
            _10292 = (compare(_name, _5416) == 0);
        if (_10292 == 0)
            goto LF;

        // 	    name = "ASSIGN_SLICE"
        RefDS(_10328);
        DeRefDS(_name);
        _name = _10328;
        goto L4;
LF:

        // 	elsif equal(name, "PLUS_I") then
        DeRef(_10292);
        if (_name == _10329)
            _10292 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_10329))
            _10292 = 0;
        else
            _10292 = (compare(_name, _10329) == 0);
        if (_10292 == 0)
            goto L10;

        // 	    name = "PLUS"
        RefDS(_10331);
        DeRefDS(_name);
        _name = _10331;
        goto L4;
L10:

        // 	elsif equal(name, "MINUS_I") then
        DeRef(_10292);
        if (_name == _10332)
            _10292 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_10332))
            _10292 = 0;
        else
            _10292 = (compare(_name, _10332) == 0);
        if (_10292 == 0)
            goto L11;

        // 	    name = "MINUS"
        RefDS(_10334);
        DeRefDS(_name);
        _name = _10334;
        goto L4;
L11:

        // 	elsif equal(name, "SC1_AND_IF") then
        DeRef(_10292);
        if (_name == _5399)
            _10292 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_5399))
            _10292 = 0;
        else
            _10292 = (compare(_name, _5399) == 0);
        if (_10292 == 0)
            goto L12;

        // 	    name = "SC1_AND"
        RefDS(_10336);
        DeRefDS(_name);
        _name = _10336;
        goto L4;
L12:

        // 	elsif equal(name, "SC1_OR_IF") then
        DeRef(_10292);
        if (_name == _10337)
            _10292 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_10337))
            _10292 = 0;
        else
            _10292 = (compare(_name, _10337) == 0);
        if (_10292 == 0)
            goto L13;

        // 	    name = "SC1_OR"
        RefDS(_10339);
        DeRefDS(_name);
        _name = _10339;
        goto L4;
L13:

        // 	elsif equal(name, "SC2_AND") then
        DeRef(_10292);
        if (_name == _10340)
            _10292 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_10340))
            _10292 = 0;
        else
            _10292 = (compare(_name, _10340) == 0);
        if (_10292 == 0)
            goto L14;

        // 	    name = "SC2_OR"
        RefDS(_10342);
        DeRefDS(_name);
        _name = _10342;
        goto L4;
L14:

        // 	elsif equal(name, "FOR_I") then
        DeRef(_10292);
        if (_name == _10343)
            _10292 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_10343))
            _10292 = 0;
        else
            _10292 = (compare(_name, _10343) == 0);
        if (_10292 == 0)
            goto L15;

        // 	    name = "FOR"
        RefDS(_10345);
        DeRefDS(_name);
        _name = _10345;
        goto L4;
L15:

        // 	elsif equal(name, "ENDFOR_INT_UP1") then
        DeRef(_10292);
        if (_name == _10346)
            _10292 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_10346))
            _10292 = 0;
        else
            _10292 = (compare(_name, _10346) == 0);
        if (_10292 == 0)
            goto L16;

        // 	    name = "ENDFOR_GENERAL"
        RefDS(_10348);
        DeRefDS(_name);
        _name = _10348;
        goto L4;
L16:

        // 	elsif equal(name, "CALL_FUNC") then
        DeRef(_10292);
        if (_name == _10349)
            _10292 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_10349))
            _10292 = 0;
        else
            _10292 = (compare(_name, _10349) == 0);
        if (_10292 == 0)
            goto L17;

        // 	    name = "CALL_PROC"
        RefDS(_10351);
        DeRefDS(_name);
        _name = _10351;
        goto L4;
L17:

        // 	elsif find(name, {"PEEK4U", "PEEK4S"}) then
        DeRef(_10292);
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _10352;
        RefDS(_10352);
        ((int *)_2)[2] = _10353;
        RefDS(_10353);
        _10292 = MAKE_SEQ(_1);
        _0 = _10292;
        _10292 = find(_name, _10292);
        DeRefDS(_0);
        if (_10292 == 0)
            goto L18;

        // 	    name = "PEEK"
        RefDS(_10356);
        DeRefDS(_name);
        _name = _10356;
        goto L4;
L18:

        // 	elsif equal(name, "POKE4") then
        DeRef(_10292);
        if (_name == _10357)
            _10292 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_10357))
            _10292 = 0;
        else
            _10292 = (compare(_name, _10357) == 0);
        if (_10292 == 0)
            goto L19;

        // 	    name = "POKE"
        RefDS(_10359);
        DeRefDS(_name);
        _name = _10359;
        goto L4;
L19:

        // 	elsif equal(name, "ABORT") then
        DeRef(_10292);
        if (_name == _10360)
            _10292 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_10360))
            _10292 = 0;
        else
            _10292 = (compare(_name, _10360) == 0);
        if (_10292 == 0)
            goto L1A;

        // 	    name = "CLOSE"
        RefDS(_10362);
        DeRefDS(_name);
        _name = _10362;
        goto L4;
L1A:

        // 	elsif equal(name, "QPRINT") then
        DeRef(_10292);
        if (_name == _10363)
            _10292 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_10363))
            _10292 = 0;
        else
            _10292 = (compare(_name, _10363) == 0);
        if (_10292 == 0)
            goto L1B;

        // 	    name = "PRINT"
        RefDS(_10365);
        DeRefDS(_name);
        _name = _10365;
        goto L4;
L1B:

        // 	elsif find(name, {"DISPLAY_VAR", "ERASE_PRIVATE_NAMES", 
        _0 = _10292;
        _1 = NewS1(3);
        _2 = (int)((s1_ptr)_1)->base;
        RefDS(_10366);
        *((int *)(_2+4)) = _10366;
        RefDS(_10367);
        *((int *)(_2+8)) = _10367;
        RefDS(_10368);
        *((int *)(_2+12)) = _10368;
        _10292 = MAKE_SEQ(_1);
        DeRef(_0);
        _0 = _10292;
        _10292 = find(_name, _10292);
        DeRefDS(_0);
        if (_10292 == 0)
            goto L1C;

        // 	    name = "PROFILE"
        RefDS(_10371);
        DeRefDS(_name);
        _name = _10371;
        goto L4;
L1C:

        // 	elsif find(name, {"ENDFOR_INT_UP", "ENDFOR_UP", "SC2_NULL", 
        _0 = _10292;
        _1 = NewS1(10);
        _2 = (int)((s1_ptr)_1)->base;
        RefDS(_10372);
        *((int *)(_2+4)) = _10372;
        RefDS(_10373);
        *((int *)(_2+8)) = _10373;
        RefDS(_10374);
        *((int *)(_2+12)) = _10374;
        RefDS(_10375);
        *((int *)(_2+16)) = _10375;
        RefDS(_10376);
        *((int *)(_2+20)) = _10376;
        RefDS(_10377);
        *((int *)(_2+24)) = _10377;
        RefDS(_10378);
        *((int *)(_2+28)) = _10378;
        RefDS(_10379);
        *((int *)(_2+32)) = _10379;
        RefDS(_10380);
        *((int *)(_2+36)) = _10380;
        RefDS(_10381);
        *((int *)(_2+40)) = _10381;
        _10292 = MAKE_SEQ(_1);
        DeRef(_0);
        _0 = _10292;
        _10292 = find(_name, _10292);
        DeRefDS(_0);
        if (_10292 == 0)
            goto L1D;

        // 	    name = "INTERNAL_ERROR" 
        RefDS(_10384);
        DeRefDS(_name);
        _name = _10384;
L1D:
L4:

        // 	operation[i] = routine_id("op" & name)
        Concat((object_ptr)&_10292, _10385, (s1_ptr)_name);
        _0 = _10292;
        _10292 = CRoutineId(409, 18, _10292);
        DeRefDS(_0);
        _2 = (int)SEQ_PTR(_18operation);
        _2 = (int)(((s1_ptr)_2)->base + _i);
        *(int *)_2 = _10292;

        // 	if operation[i] = -1 then
        _2 = (int)SEQ_PTR(_18operation);
        _10292 = (int)*(((s1_ptr)_2)->base + _i);
        if (_10292 != -1)
            goto L1E;

        // 	    InternalErr("no routine id for op" & name)
        Concat((object_ptr)&_10292, _10390, (s1_ptr)_name);
        RefDS(_10292);
        _6InternalErr(_10292);
L1E:

        //     end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    // end procedure
    DeRef(_name);
    DeRef(_10292);
    return 0;
    ;
}


int _18do_exec(int _start_pc)
{
    int _10392;
    int _0, _1, _2;
    

    //     pc = start_pc
    _18pc = 1;

    //     in_loop = {}
    RefDS(_39);
    DeRef(_18in_loop);
    _18in_loop = _39;

    //     label_map = {}
    RefDS(_39);
    DeRefi(_18label_map);
    _18label_map = _39;

    //     all_done = FALSE
    _18all_done = 0;

    //     while not all_done do 
L1:
    if (_18all_done != 0)
        goto L2;

    // 	previous_previous_op = previous_op
    _18previous_previous_op = _18previous_op;

    // 	previous_op = opcode
    _18previous_op = _18opcode;

    // 	opcode = Code[pc]
    _2 = (int)SEQ_PTR(_4Code);
    _18opcode = (int)*(((s1_ptr)_2)->base + _18pc);
    if (!IS_ATOM_INT(_18opcode))
        _18opcode = (long)DBL_PTR(_18opcode)->dbl;

    // 	target_type = TYPE_OBJECT
    _18target_type = 16;

    // 	target_val = novalue      -- integer value or sequence length
    RefDS(_9novalue);
    DeRef(_18target_val);
    _18target_val = _9novalue;

    // 	target_elem = TYPE_OBJECT -- seqeunce element type
    _18target_elem = 16;

    // 	atom_type = TYPE_ATOM
    _18atom_type = 4;

    // 	intcode2 = ""
    RefDS(_39);
    DeRefi(_18intcode2);
    _18intcode2 = _39;

    // 	dblfn = ""
    RefDS(_39);
    DeRefi(_18dblfn);
    _18dblfn = _39;

    // 	intcode_extra = ""
    RefDS(_39);
    DeRefi(_18intcode_extra);
    _18intcode_extra = _39;

    // 	call_proc(operation[opcode], {})
    _2 = (int)SEQ_PTR(_18operation);
    _10392 = (int)*(((s1_ptr)_2)->base + _18opcode);
    _0 = (int)_00[_10392].addr;
    (*(int (*)())_0)(
                         );

    //     end while
    goto L1;
L2:

    // end procedure       
    return 0;
    ;
}


int _18Execute(int _proc)
{
    int _10395 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_proc)) {
        _1 = (long)(DBL_PTR(_proc)->dbl);
        DeRefDS(_proc);
        _proc = _1;
    }

    //     CurrentSub = proc
    _4CurrentSub = _proc;

    //     Code = SymTab[CurrentSub][S_CODE]
    _2 = (int)SEQ_PTR(_4SymTab);
    _10395 = (int)*(((s1_ptr)_2)->base + _4CurrentSub);
    RefDS(_10395);
    DeRef(_4Code);
    _2 = (int)SEQ_PTR(_10395);
    _4Code = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_4Code);

    //     do_exec(1)
    _18do_exec(1);

    //     indent = 0
    _9indent = 0;

    //     temp_indent = 0
    _9temp_indent = 0;

    // end procedure
    DeRefDS(_10395);
    return 0;
    ;
}


int _18hex_char(int _c)
{
    int _10404 = 0;
    int _10401;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_c)) {
        _1 = (long)(DBL_PTR(_c)->dbl);
        DeRefDS(_c);
        _c = _1;
    }

    //     return "\\x" & hex_chars[1+floor(c/16)] & hex_chars[1+remainder(c, 16)]
    if (16 > 0 && _c >= 0) {
        _10401 = _c / 16;
    }
    else {
        temp_dbl = floor((double)_c / (double)16);
        _10401 = (long)temp_dbl;
    }
    _10401 = _10401 + 1;
    _2 = (int)SEQ_PTR(_18hex_chars);
    _10401 = (int)*(((s1_ptr)_2)->base + _10401);
    _10404 = (_c % 16);
    _10404 = _10404 + 1;
    _2 = (int)SEQ_PTR(_18hex_chars);
    _10404 = (int)*(((s1_ptr)_2)->base + _10404);
    {
        int concat_list[3];

        concat_list[0] = _10404;
        concat_list[1] = _10401;
        concat_list[2] = _10400;
        Concat_N((object_ptr)&_10404, concat_list, 3);
    }
    return _10404;
    ;
}


int _18BackEnd(int _ignore)
{
    int _w;
    int _tp;
    int _string = 0;
    int _init_name = 0;
    int _c;
    int _tp_count;
    int _xterm = 0;
    int _use_hex;
    int _10539 = 0;
    int _10408 = 0;
    int _10433 = 0;
    int _0, _1, _2;
    

    //     close(c_code)
    EClose(_9c_code);

    //     emit_c_output = FALSE
    _9emit_c_output = 0;

    //     slist = s_expand(slist)
    RefDS(_4slist);
    _0 = _11s_expand(_4slist);
    DeRef1(_4slist);
    _4slist = _0;

    //     Pass = 1
    _16Pass = 1;

    //     while Pass < LAST_PASS do
L1:
    if (_16Pass >= 7)
        goto L2;

    // 	main_temps()
    _18main_temps();

    // 	Execute(TopLevelSub)
    _18Execute(_4TopLevelSub);

    // 	GenerateUserRoutines()
    _16GenerateUserRoutines();

    // 	DeclareRoutineList() -- forces routine_id target 
    _16DeclareRoutineList();

    // 	PromoteTypeInfo()    -- at very end after each FULL pass: 
    _16PromoteTypeInfo();

    // 	Pass += 1
    _16Pass = _16Pass + 1;

    //     end while
    goto L1;
L2:

    //     emit_c_output = TRUE
    _9emit_c_output = 1;

    //     c_code = open("main-.c", "w")
    _9c_code = EOpen(_10411, _10412);

    //     if c_code = -1 then
    if (_9c_code != -1)
        goto L3;

    // 	CompileErr("Can't open main-.c for output\n")
    RefDS(_10415);
    _6CompileErr(_10415);
L3:

    //     version()
    _16version();

    //     if EDOS then
    if (_4EDOS == 0)
        goto L4;

    // 	if sequence(dj_path) then
    DeRef1(_10408);
    _10408 = IS_SEQUENCE(_4dj_path);
    if (_10408 == 0)
        goto L5;

    // 	    c_puts("#include <go32.h>\n")
    RefDS(_10417);
    _9c_puts(_10417);
L5:
L4:

    //     c_puts("#include <time.h>\n")
    RefDS(_10418);
    _9c_puts(_10418);

    //     c_puts("#include \"")
    RefDS(_10419);
    _9c_puts(_10419);

    //     c_puts(eudir)
    Ref(_4eudir);
    _9c_puts(_4eudir);

    //     if ELINUX then
    if (_4ELINUX == 0)
        goto L6;

    // 	c_puts("/include/euphoria.h\"\n")
    RefDS(_10420);
    _9c_puts(_10420);

    // 	c_puts("#include <unistd.h>\n")
    RefDS(_10421);
    _9c_puts(_10421);
    goto L7;
L6:

    // 	c_puts("\\include\\euphoria.h\"\n")
    RefDS(_10422);
    _9c_puts(_10422);
L7:

    //     if sequence(bor_path) then
    DeRef1(_10408);
    _10408 = IS_SEQUENCE(_4bor_path);
    if (_10408 == 0)
        goto L8;

    // 	c_puts("#include <float.h>\n")
    RefDS(_10424);
    _9c_puts(_10424);
L8:

    //     c_puts("#include \"main-.h\"\n\n")
    RefDS(_10425);
    _9c_puts(_10425);

    //     c_puts("int Argc;\n")
    RefDS(_10426);
    _9c_puts(_10426);

    //     c_hputs("extern int Argc;\n")
    RefDS(_10427);
    _9c_hputs(_10427);

    //     c_puts("char **Argv;\n")
    RefDS(_10428);
    _9c_puts(_10428);

    //     c_hputs("extern char **Argv;\n")
    RefDS(_10429);
    _9c_hputs(_10429);

    //     if EWINDOWS then
    if (_4EWINDOWS == 0)
        goto L9;

    // 	c_puts("unsigned default_heap;\n")
    RefDS(_10430);
    _9c_puts(_10430);

    // 	if sequence(wat_path) or sequence(bor_path) then
    DeRef1(_10408);
    _10408 = IS_SEQUENCE(_4wat_path);
    if (_10408 != 0) {
        goto LA;
    }
    DeRef1(_10433);
    _10433 = IS_SEQUENCE(_4bor_path);
LB:
    if (_10433 == 0)
        goto LC;
LA:

    // 	    c_puts("__declspec(dllimport) unsigned __stdcall GetProcessHeap(void);\n")
    RefDS(_10434);
    _9c_puts(_10434);
    goto LD;
LC:

    // 	    c_puts("unsigned __stdcall GetProcessHeap(void);\n")
    RefDS(_10435);
    _9c_puts(_10435);
LD:
L9:

    //     if EDJGPP then

    //     c_puts("unsigned long *peek4_addr;\n")
    RefDS(_10437);
    _9c_puts(_10437);

    //     c_hputs("extern unsigned long *peek4_addr;\n")
    RefDS(_10438);
    _9c_hputs(_10438);

    //     c_puts("unsigned char *poke_addr;\n")
    RefDS(_10439);
    _9c_puts(_10439);

    //     c_hputs("extern unsigned char *poke_addr;\n")
    RefDS(_10440);
    _9c_hputs(_10440);

    //     c_puts("unsigned long *poke4_addr;\n")
    RefDS(_10441);
    _9c_puts(_10441);

    //     c_hputs("extern unsigned long *poke4_addr;\n")
    RefDS(_10442);
    _9c_hputs(_10442);

    //     c_puts("struct d temp_d;\n")
    RefDS(_10443);
    _9c_puts(_10443);

    //     c_hputs("extern struct d temp_d;\n")
    RefDS(_10444);
    _9c_hputs(_10444);

    //     c_puts("double temp_dbl;\n")
    RefDS(_10445);
    _9c_puts(_10445);

    //     c_hputs("extern double temp_dbl;\n")
    RefDS(_10446);
    _9c_hputs(_10446);

    //     c_puts("char *stack_base;\n")
    RefDS(_10447);
    _9c_puts(_10447);

    //     c_hputs("extern char *stack_base;\n")
    RefDS(_10448);
    _9c_hputs(_10448);

    //     if total_stack_size = -1 then
    if (_16total_stack_size != -1)
        goto LE;

    // 	if tasks_created then
    if (_18tasks_created == 0)
        goto LF;

    // 	    total_stack_size = (1016 + 8) * 1024 
    DeRef1(_10433);
    _10433 = 1024;
    _16total_stack_size = 1048576;
    goto L10;
LF:

    // 	    total_stack_size = (248 + 8) * 1024
    DeRef1(_10433);
    _10433 = 256;
    _16total_stack_size = 262144;
L10:
LE:

    //     if EDOS and sequence(dj_path) then
    if (_4EDOS == 0) {
        goto L11;
    }
    DeRef1(_10408);
    _10408 = IS_SEQUENCE(_4dj_path);
L12:
    if (_10408 == 0)
        goto L11;

    // 	c_printf("unsigned _stklen=%d;\n", total_stack_size)
    RefDS(_10459);
    _9c_printf(_10459, _16total_stack_size);
L11:

    //     c_printf("int total_stack_size = %d;\n", total_stack_size)
    RefDS(_10460);
    _9c_printf(_10460, _16total_stack_size);

    //     c_hputs("extern int total_stack_size;\n")
    RefDS(_10461);
    _9c_hputs(_10461);

    //     if EXTRA_CHECK then

    //     if EWINDOWS then
    if (_4EWINDOWS == 0)
        goto L13;

    // 	if dll_option then
    if (_16dll_option == 0)
        goto L14;

    // 	    if sequence(wat_path) then
    DeRef1(_10408);
    _10408 = IS_SEQUENCE(_4wat_path);
    if (_10408 == 0)
        goto L15;

    // 		c_stmt0("\nint __stdcall _CRT_INIT (int, int, void *);\n")
    RefDS(_10464);
    _16c_stmt0(_10464);

    // 		c_stmt0("\n")
    RefDS(_629);
    _16c_stmt0(_629);
L15:

    // 	    c_stmt0("\nvoid EuInit()\n")  -- __declspec(dllexport) __stdcall 
    RefDS(_10465);
    _16c_stmt0(_10465);
    goto L16;
L14:

    // 	    if sequence(bor_path) and con_option then
    DeRef1(_10408);
    _10408 = IS_SEQUENCE(_4bor_path);
    if (_10408 == 0) {
        goto L17;
    }
L18:
    if (_16con_option == 0)
        goto L17;

    // 		c_stmt0("\nvoid main(int argc, char *argv[])\n")
    RefDS(_10468);
    _16c_stmt0(_10468);
    goto L16;
L17:

    // 		c_stmt0("\nvoid __stdcall WinMain(void *hInstance, void *hPrevInstance, char *szCmdLine, int iCmdShow)\n")
    RefDS(_10469);
    _16c_stmt0(_10469);
L19:
L1A:
    goto L16;
L13:

    //     elsif ELINUX then
    if (_4ELINUX == 0)
        goto L1B;

    // 	if dll_option then
    if (_16dll_option == 0)
        goto L1C;

    // 	    c_stmt0("\nvoid _init()\n")
    RefDS(_10470);
    _16c_stmt0(_10470);
    goto L16;
L1C:

    // 	    c_stmt0("\nvoid main(int argc, char *argv[])\n")
    RefDS(_10468);
    _16c_stmt0(_10468);
L1D:
    goto L16;
L1B:

    // 	c_stmt0("\nvoid main(int argc, char *argv[])\n")
    RefDS(_10468);
    _16c_stmt0(_10468);
L16:

    //     c_stmt0("{\n")
    RefDS(_5169);
    _16c_stmt0(_5169);

    //     main_temps()
    _18main_temps();

    //     if EWINDOWS then
    if (_4EWINDOWS == 0)
        goto L1E;

    // 	if dll_option then
    if (_16dll_option == 0)
        goto L1F;

    // 	    c_stmt0("\nArgc = 0;\n")
    RefDS(_10471);
    _16c_stmt0(_10471);

    // 	    c_stmt0("default_heap = GetProcessHeap();\n")
    RefDS(_10472);
    _16c_stmt0(_10472);
    goto L20;
L1F:

    // 	    if sequence(bor_path) and con_option then
    DeRef1(_10408);
    _10408 = IS_SEQUENCE(_4bor_path);
    if (_10408 == 0) {
        goto L21;
    }
L22:
    if (_16con_option == 0)
        goto L21;

    // 		c_stmt0("void *hInstance;\n\n")
    RefDS(_10475);
    _16c_stmt0(_10475);

    // 		c_stmt0("hInstance = 0;\n")
    RefDS(_10476);
    _16c_stmt0(_10476);
    goto L23;
L21:

    // 		c_stmt0("int argc;\n")
    RefDS(_10477);
    _16c_stmt0(_10477);

    // 		c_stmt0("char **argv;\n\n")
    RefDS(_10478);
    _16c_stmt0(_10478);
L23:

    // 	    if sequence(bor_path) then
    DeRef1(_10408);
    _10408 = IS_SEQUENCE(_4bor_path);
    if (_10408 == 0)
        goto L24;

    // 		c_stmt0("_control87(MCW_EM,MCW_EM);\n")
    RefDS(_10480);
    _16c_stmt0(_10480);
L24:

    // 	    c_stmt0("default_heap = GetProcessHeap();\n")
    RefDS(_10472);
    _16c_stmt0(_10472);

    // 	    if sequence(bor_path) and con_option then
    DeRef1(_10408);
    _10408 = IS_SEQUENCE(_4bor_path);
    if (_10408 == 0) {
        goto L25;
    }
L26:
    if (_16con_option == 0)
        goto L25;

    // 		c_stmt0("Argc = argc;\n")
    RefDS(_10483);
    _16c_stmt0(_10483);

    // 		c_stmt0("Argv = argv;\n")
    RefDS(_10484);
    _16c_stmt0(_10484);
    goto L27;
L25:

    // 		c_stmt0("argc = 1;\n")
    RefDS(_10485);
    _16c_stmt0(_10485);

    // 		c_stmt0("Argc = 1;\n")
    RefDS(_10486);
    _16c_stmt0(_10486);

    // 		c_stmt0("argv = make_arg_cv(szCmdLine, &argc);\n")
    RefDS(_10487);
    _16c_stmt0(_10487);
L27:

    // 	    c_stmt0("winInstance = hInstance;\n")
    RefDS(_10488);
    _16c_stmt0(_10488);
L28:
    goto L20;
L1E:

    //     elsif ELINUX then
    if (_4ELINUX == 0)
        goto L29;

    // 	if dll_option then
    if (_16dll_option == 0)
        goto L2A;

    // 	    c_stmt0("\nArgc = 0;\n")
    RefDS(_10471);
    _16c_stmt0(_10471);
    goto L20;
L2A:

    // 	    c_stmt0("Argc = argc;\n")
    RefDS(_10483);
    _16c_stmt0(_10483);

    // 	    c_stmt0("Argv = argv;\n")
    RefDS(_10484);
    _16c_stmt0(_10484);
L2B:
    goto L20;
L29:

    // 	c_stmt0("Argc = argc;\n")
    RefDS(_10483);
    _16c_stmt0(_10483);

    // 	c_stmt0("Argv = argv;\n")
    RefDS(_10484);
    _16c_stmt0(_10484);
L20:

    //     if not dll_option then
    if (_16dll_option != 0)
        goto L2C;

    // 	c_stmt0("stack_base = (char *)&_0;\n")
    RefDS(_10490);
    _16c_stmt0(_10490);
L2C:

    //     if EWINDOWS then
    if (_4EWINDOWS == 0)
        goto L2D;

    // 	if atom(wat_path) then
    DeRef1(_10408);
    _10408 = IS_ATOM(_4wat_path);
    if (_10408 == 0)
        goto L2E;

    // 	    c_stmt0("eu_startup(_00, _01, 1, (int)CLOCKS_PER_SEC, (int)CLOCKS_PER_SEC);\n")
    RefDS(_10492);
    _16c_stmt0(_10492);
    goto L2F;
L2E:

    // 	    c_stmt0("eu_startup(_00, _01, 1, (int)CLOCKS_PER_SEC, (int)CLK_TCK);\n")  
    RefDS(_10493);
    _16c_stmt0(_10493);
L30:
    goto L2F;
L2D:

    // 	c_puts("#ifdef CLK_TCK\n")
    RefDS(_10494);
    _9c_puts(_10494);

    // 	c_stmt0("eu_startup(_00, _01, 1, (int)CLOCKS_PER_SEC, (int)CLK_TCK);\n")
    RefDS(_10493);
    _16c_stmt0(_10493);

    // 	c_puts("#else\n")
    RefDS(_10495);
    _9c_puts(_10495);

    // 	c_stmt0("eu_startup(_00, _01, 1, (int)CLOCKS_PER_SEC, (int)sysconf(_SC_CLK_TCK));\n")
    RefDS(_10496);
    _16c_stmt0(_10496);

    // 	c_puts("#endif\n")
    RefDS(_10497);
    _9c_puts(_10497);
L2F:

    //     c_stmt0("init_literal();\n")
    RefDS(_10498);
    _16c_stmt0(_10498);

    //     if not dll_option then
    if (_16dll_option != 0)
        goto L31;

    // 	c_stmt0("shift_args(argc, argv);\n")
    RefDS(_10500);
    _16c_stmt0(_10500);
L31:

    //     Execute(TopLevelSub)
    _18Execute(_4TopLevelSub);

    //     indent = 4
    _9indent = 4;

    //     if dll_option then
    if (_16dll_option == 0)
        goto L32;

    // 	c_stmt0(";\n")
    RefDS(_4460);
    _16c_stmt0(_4460);
    goto L33;
L32:

    // 	c_stmt0("Cleanup(0);\n")
    RefDS(_10501);
    _16c_stmt0(_10501);
L33:

    //     c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    //     if EWINDOWS then
    if (_4EWINDOWS == 0)
        goto L34;

    // 	if dll_option then
    if (_16dll_option == 0)
        goto L35;

    // 	    c_stmt0("\n")
    RefDS(_629);
    _16c_stmt0(_629);

    // 	    if atom(bor_path) then
    DeRef1(_10408);
    _10408 = IS_ATOM(_4bor_path);
    if (_10408 == 0)
        goto L36;

    // 		c_stmt0("int __stdcall LibMain(int hDLL, int Reason, void *Reserved)\n")
    RefDS(_10503);
    _16c_stmt0(_10503);
    goto L37;
L36:

    // 		c_stmt0("int __declspec (dllexport) __stdcall DllMain(int hDLL, int Reason, void *Reserved)\n")
    RefDS(_10504);
    _16c_stmt0(_10504);
L37:

    // 	    c_stmt0("{\n")
    RefDS(_5169);
    _16c_stmt0(_5169);

    // 	    c_stmt0("if (Reason == 1)\n")
    RefDS(_10505);
    _16c_stmt0(_10505);

    // 	    c_stmt0("EuInit();\n")
    RefDS(_10506);
    _16c_stmt0(_10506);

    // 	    c_stmt0("return 1;\n")
    RefDS(_10507);
    _16c_stmt0(_10507);

    // 	    c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
L35:
L34:

    //     start_emake()
    _16start_emake();

    //     GenerateUserRoutines()  -- needs init_name_num
    _16GenerateUserRoutines();

    //     close(c_code)
    EClose(_9c_code);

    //     c_code = open("init-.c", "a")
    _9c_code = EOpen(_10508, _10509);

    //     if c_code = -1 then
    if (_9c_code != -1)
        goto L38;

    // 	CompileErr("Can't open init-.c for append\n")
    RefDS(_10512);
    _6CompileErr(_10512);
L38:

    //     DeclareFileVars()
    _16DeclareFileVars();

    //     DeclareRoutineList()
    _16DeclareRoutineList();

    //     DeclareNameSpaceList()
    _16DeclareNameSpaceList();

    //     c_stmt0("void init_literal()\n{\n")
    RefDS(_10513);
    _16c_stmt0(_10513);

    //     tp = literal_init
    _tp = _10literal_init;

    //     c_stmt0("extern double sqrt();\n")
    RefDS(_10514);
    _16c_stmt0(_10514);

    //     tp_count = 0
    _tp_count = 0;

    //     while tp != 0 do
L39:
    if (_tp == 0)
        goto L3A;

    // 	if tp_count > INIT_CHUNK then
    if (_tp_count <= 2500)
        goto L3B;

    // 	    c_stmt0("init_literal")
    RefDS(_10517);
    _16c_stmt0(_10517);

    // 	    c_printf("%d();\n", init_name_num)
    RefDS(_7647);
    _9c_printf(_7647, _9init_name_num);

    // 	    c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	    init_name = sprintf("init-%d", init_name_num)
    DeRefi(_init_name);
    _init_name = EPrintf(-9999999, _10518, _9init_name_num);

    // 	    new_c_file(init_name)
    RefDS(_init_name);
    _16new_c_file(_init_name);

    // 	    c_stmt0("init_literal")
    RefDS(_10517);
    _16c_stmt0(_10517);

    // 	    c_printf("%d()\n", init_name_num)
    RefDS(_7649);
    _9c_printf(_7649, _9init_name_num);

    // 	    c_stmt0("{\n")
    RefDS(_5169);
    _16c_stmt0(_5169);

    // 	    c_stmt0("extern double sqrt();\n")
    RefDS(_10514);
    _16c_stmt0(_10514);

    // 	    init_name_num += 1
    _9init_name_num = _9init_name_num + 1;

    // 	    tp_count = 0
    _tp_count = 0;
L3B:

    // 	c_stmt0("_")
    RefDS(_10521);
    _16c_stmt0(_10521);

    // 	if atom(SymTab[tp][S_OBJ]) then -- can't be NOVALUE
    DeRef(_10408);
    _2 = (int)SEQ_PTR(_4SymTab);
    _10408 = (int)*(((s1_ptr)_2)->base + _tp);
    RefDS(_10408);
    _0 = _10408;
    _2 = (int)SEQ_PTR(_10408);
    _10408 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_10408);
    DeRefDS(_0);
    _0 = _10408;
    _10408 = IS_ATOM(_10408);
    DeRef(_0);
    if (_10408 == 0)
        goto L3C;

    // 	    c_printf("%d = NewDouble((double)", SymTab[tp][S_TEMP_NAME])
    _2 = (int)SEQ_PTR(_4SymTab);
    _10408 = (int)*(((s1_ptr)_2)->base + _tp);
    RefDS(_10408);
    _0 = _10408;
    _2 = (int)SEQ_PTR(_10408);
    _10408 = (int)*(((s1_ptr)_2)->base + 31);
    Ref(_10408);
    DeRefDS(_0);
    RefDS(_10525);
    Ref(_10408);
    _9c_printf(_10525, _10408);

    // 	    c_printf8(SymTab[tp][S_OBJ])
    DeRef(_10408);
    _2 = (int)SEQ_PTR(_4SymTab);
    _10408 = (int)*(((s1_ptr)_2)->base + _tp);
    RefDS(_10408);
    _0 = _10408;
    _2 = (int)SEQ_PTR(_10408);
    _10408 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_10408);
    DeRefDS(_0);
    Ref(_10408);
    _9c_printf8(_10408);

    // 	    c_puts(");\n")
    RefDS(_4675);
    _9c_puts(_4675);
    goto L3D;
L3C:

    // 	    c_printf("%d = NewString(\"", SymTab[tp][S_TEMP_NAME])
    DeRef(_10408);
    _2 = (int)SEQ_PTR(_4SymTab);
    _10408 = (int)*(((s1_ptr)_2)->base + _tp);
    RefDS(_10408);
    _0 = _10408;
    _2 = (int)SEQ_PTR(_10408);
    _10408 = (int)*(((s1_ptr)_2)->base + 31);
    Ref(_10408);
    DeRefDS(_0);
    RefDS(_10530);
    Ref(_10408);
    _9c_printf(_10530, _10408);

    // 	    string = SymTab[tp][S_OBJ]
    DeRef(_10408);
    _2 = (int)SEQ_PTR(_4SymTab);
    _10408 = (int)*(((s1_ptr)_2)->base + _tp);
    RefDS(_10408);
    DeRef(_string);
    _2 = (int)SEQ_PTR(_10408);
    _string = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_string);

    // 	    use_hex = FALSE
    _use_hex = 0;

    // 	    for elem = 1 to length(string) do
    DeRefDS(_10408);
    _10408 = SEQ_PTR(_string)->length;
    { int _elem;
        _elem = 1;
L3E:
        if (_elem > _10408)
            goto L3F;

        // 		if (string[elem] < 32 or string[elem] > 127) and 
        DeRef(_10433);
        _2 = (int)SEQ_PTR(_string);
        _10433 = (int)*(((s1_ptr)_2)->base + _elem);
        Ref(_10433);
        _0 = _10433;
        if (IS_ATOM_INT(_10433)) {
            _10433 = (_10433 < 32);
        }
        else {
            _10433 = binary_op(LESS, _10433, 32);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_10433)) {
            if (_10433 != 0) {
                DeRef(_10433);
                _10433 = 1;
                goto L40;
            }
        }
        else {
            if (DBL_PTR(_10433)->dbl != 0.0) {
                DeRef(_10433);
                _10433 = 1;
                goto L40;
            }
        }
        DeRef(_10539);
        _2 = (int)SEQ_PTR(_string);
        _10539 = (int)*(((s1_ptr)_2)->base + _elem);
        Ref(_10539);
        _0 = _10539;
        if (IS_ATOM_INT(_10539)) {
            _10539 = (_10539 > 127);
        }
        else {
            _10539 = binary_op(GREATER, _10539, 127);
        }
        DeRef(_0);
        DeRef(_10433);
        if (IS_ATOM_INT(_10539))
            _10433 = (_10539 != 0);
        else
            _10433 = DBL_PTR(_10539)->dbl != 0.0;
L40:
        if (_10433 == 0) {
            goto L41;
        }
        DeRef(_10433);
        _2 = (int)SEQ_PTR(_string);
        _10433 = (int)*(((s1_ptr)_2)->base + _elem);
        Ref(_10433);
        _0 = _10433;
        _10433 = find(_10433, _10543);
        DeRef(_0);
        _10433 = (_10433 == 0);
L42:
        if (_10433 == 0)
            goto L41;

        // 		    use_hex = TRUE
        _use_hex = 1;
L41:

        // 	    end for
        _elem = _elem + 1;
        goto L3E;
L3F:
        ;
    }

    // 	    if use_hex then
    if (_use_hex == 0)
        goto L43;

    // 		for elem = 1 to length(string) do
    DeRef(_10433);
    _10433 = SEQ_PTR(_string)->length;
    { int _elem;
        _elem = 1;
L44:
        if (_elem > _10433)
            goto L45;

        // 		    c_puts(hex_char(string[elem]))
        DeRef(_10539);
        _2 = (int)SEQ_PTR(_string);
        _10539 = (int)*(((s1_ptr)_2)->base + _elem);
        Ref(_10539);
        Ref(_10539);
        _0 = _10539;
        _10539 = _18hex_char(_10539);
        DeRef(_0);
        RefDS(_10539);
        _9c_puts(_10539);

        // 		    if remainder(elem, 15) = 0 and elem < length(string) then
        DeRefDSi(_10539);
        _10539 = (_elem % 15);
        _10539 = (_10539 == 0);
        if (_10539 == 0) {
            goto L46;
        }
        DeRef(_10408);
        _10408 = SEQ_PTR(_string)->length;
        _10408 = (_elem < _10408);
L47:
        if (_10408 == 0)
            goto L46;

        // 			c_puts("\"\n\"") -- start a new string chunk, 
        RefDS(_10554);
        _9c_puts(_10554);
L46:

        // 		end for
        _elem = _elem + 1;
        goto L44;
L45:
        ;
    }
    goto L48;
L43:

    // 		for elem = 1 to length(string) do
    DeRef(_10408);
    _10408 = SEQ_PTR(_string)->length;
    { int _elem;
        _elem = 1;
L49:
        if (_elem > _10408)
            goto L4A;

        // 		    c = string[elem]
        _2 = (int)SEQ_PTR(_string);
        _c = (int)*(((s1_ptr)_2)->base + _elem);
        if (!IS_ATOM_INT(_c))
            _c = (long)DBL_PTR(_c)->dbl;

        // 		    if c = '\t' then
        if (_c != 9)
            goto L4B;

        // 			c_puts("\\t")
        RefDS(_10558);
        _9c_puts(_10558);
        goto L4C;
L4B:

        // 		    elsif c = '\n' then
        if (_c != 10)
            goto L4D;

        // 			c_puts("\\n")
        RefDS(_10560);
        _9c_puts(_10560);
        goto L4C;
L4D:

        // 		    elsif c = '\r' then
        if (_c != 13)
            goto L4E;

        // 			c_puts("\\r")
        RefDS(_10562);
        _9c_puts(_10562);
        goto L4C;
L4E:

        // 		    elsif c = '\"' then
        if (_c != 34)
            goto L4F;

        // 			c_puts("\\\"")
        RefDS(_10564);
        _9c_puts(_10564);
        goto L4C;
L4F:

        // 		    elsif c = '\\' then
        if (_c != 92)
            goto L50;

        // 			c_puts("\\\\")
        RefDS(_10566);
        _9c_puts(_10566);
        goto L4C;
L50:

        // 			c_putc(c)
        _9c_putc(_c);
L4C:

        // 		end for
        _elem = _elem + 1;
        goto L49;
L4A:
        ;
    }
L48:

    // 	    c_puts("\");\n")
    RefDS(_10567);
    _9c_puts(_10567);
L3D:

    // 	tp = SymTab[tp][S_NEXT]
    DeRef(_10539);
    _2 = (int)SEQ_PTR(_4SymTab);
    _10539 = (int)*(((s1_ptr)_2)->base + _tp);
    RefDS(_10539);
    _2 = (int)SEQ_PTR(_10539);
    _tp = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_tp))
        _tp = (long)DBL_PTR(_tp)->dbl;

    // 	tp_count += 1
    _tp_count = _tp_count + 1;

    //     end while
    goto L39;
L3A:

    //     c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    //     c_hputs("extern int TraceOn;\n")
    RefDS(_10571);
    _9c_hputs(_10571);

    //     c_hputs("extern object_ptr rhs_slice_target;\n")
    RefDS(_10572);
    _9c_hputs(_10572);

    //     c_hputs("extern s1_ptr *assign_slice_seq;\n")
    RefDS(_10573);
    _9c_hputs(_10573);

    //     c_hputs("extern object last_r_file_no;\n")
    RefDS(_10574);
    _9c_hputs(_10574);

    //     c_hputs("extern void *last_r_file_ptr;\n")
    RefDS(_10575);
    _9c_hputs(_10575);

    //     c_hputs("extern int in_from_keyb;\n")
    RefDS(_10576);
    _9c_hputs(_10576);

    //     c_hputs("extern void *xstdin;\n")
    RefDS(_10577);
    _9c_hputs(_10577);

    //     c_hputs("extern struct tcb *tcb;\n")
    RefDS(_10578);
    _9c_hputs(_10578);

    //     c_hputs("extern int current_task;\n")
    RefDS(_10579);
    _9c_hputs(_10579);

    //     if EWINDOWS then
    if (_4EWINDOWS == 0)
        goto L51;

    // 	c_hputs("extern void *winInstance;\n\n")
    RefDS(_10580);
    _9c_hputs(_10580);
L51:

    //     close(c_code)
    EClose(_9c_code);

    //     close(c_h)
    EClose(_9c_h);

    //     finish_emake()
    _16finish_emake();

    //     screen_output(STDERR, sprintf("\n%d .c files were created.\n", cfile_count+2))
    DeRef1(_10539);
    _10539 = _4cfile_count + 2;
    if ((long)((unsigned long)_10539 + (unsigned long)HIGH_BITS) >= 0) 
        _10539 = NewDouble((double)_10539);
    _0 = _10539;
    _10539 = EPrintf(-9999999, _10581, _10539);
    DeRef1(_0);
    RefDS(_10539);
    _6screen_output(2, _10539);

    //     if ELINUX then
    if (_4ELINUX == 0)
        goto L52;

    // 	if dll_option then
    if (_16dll_option == 0)
        goto L53;

    // 	    screen_output(STDERR, "To build your shared library, type: ./emake\n")
    RefDS(_10584);
    _6screen_output(2, _10584);
    goto L54;
L53:

    // 	    screen_output(STDERR, "To build your executable file, type: ./emake\n")
    RefDS(_10585);
    _6screen_output(2, _10585);
L55:
    goto L54;
L52:

    // 	if dll_option then
    if (_16dll_option == 0)
        goto L56;

    // 	    screen_output(STDERR, "To build your .dll file, type: emake\n")
    RefDS(_10586);
    _6screen_output(2, _10586);
    goto L57;
L56:

    // 	    screen_output(STDERR, "To build your .exe file, type: emake\n")
    RefDS(_10587);
    _6screen_output(2, _10587);
L57:
L54:

    // end procedure
    DeRef1(_string);
    DeRef1(_init_name);
    DeRef1(_xterm);
    DeRef(_10539);
    DeRef(_10408);
    DeRef(_10433);
    return 0;
    ;
}


