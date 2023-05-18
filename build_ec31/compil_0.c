// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _18seg_peek4(int _target, int _source, int _dbl)
{
    int _5834 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_target)) {
        _1 = (long)(DBL_PTR(_target)->dbl);
        DeRefDS(_target);
        _target = _1;
    }
    if (!IS_ATOM_INT(_source)) {
        _1 = (long)(DBL_PTR(_source)->dbl);
        DeRefDS(_source);
        _source = _1;
    }
    if (!IS_ATOM_INT(_dbl)) {
        _1 = (long)(DBL_PTR(_dbl)->dbl);
        DeRefDS(_dbl);
        _dbl = _1;
    }

    //     if atom(dj_path) then
    _5834 = IS_ATOM(_4dj_path);
    if (_5834 == 0)
        goto L1;

    // 	if dbl then
    if (_dbl == 0)
        goto L2;

    // 	    c_stmt("@ = *(unsigned long *)(unsigned long)(DBL_PTR(@)->dbl);\n",
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _target;
    ((int *)_2)[2] = _source;
    _5834 = MAKE_SEQ(_1);
    RefDS(_5835);
    RefDS(_5834);
    _16c_stmt(_5835, _5834);
    goto L3;
L2:

    // 	    c_stmt("@ = *(unsigned long *)@;\n", {target, source})
    DeRef(_5834);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _target;
    ((int *)_2)[2] = _source;
    _5834 = MAKE_SEQ(_1);
    RefDS(_5837);
    RefDS(_5834);
    _16c_stmt(_5837, _5834);
L4:
    goto L3;
L1:

    // 	if dbl then
    if (_dbl == 0)
        goto L5;

    // 	    c_stmt("_1 = (int)(unsigned)DBL_PTR(@)->dbl;\n", source)
    RefDS(_5825);
    _16c_stmt(_5825, _source);

    // 	    c_stmt0("if ((unsigned)_1 > LOW_MEMORY_MAX)\n")
    RefDS(_5826);
    _16c_stmt0(_5826);

    // 	    c_stmt("@ = *(unsigned long *)_1;\n", target)
    RefDS(_5839);
    _16c_stmt(_5839, _target);

    // 	    c_stmt0("else\n")
    RefDS(_5799);
    _16c_stmt0(_5799);

    // 	    c_stmt("@ = _farpeekl(_go32_info_block.selector_for_linear_memory, (unsigned)_1);\n", 
    RefDS(_5840);
    _16c_stmt(_5840, _target);
    goto L6;
L5:

    // 	    c_stmt("if ((unsigned)@ > LOW_MEMORY_MAX)\n", source)
    RefDS(_5830);
    _16c_stmt(_5830, _source);

    // 	    c_stmt("@ = *(unsigned long *)@;\n", {target, source})
    DeRef(_5834);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _target;
    ((int *)_2)[2] = _source;
    _5834 = MAKE_SEQ(_1);
    RefDS(_5837);
    RefDS(_5834);
    _16c_stmt(_5837, _5834);

    // 	    c_stmt0("else\n")
    RefDS(_5799);
    _16c_stmt0(_5799);

    // 	    c_stmt("@ = _farpeekl(_go32_info_block.selector_for_linear_memory, (unsigned)@);\n", 
    DeRefDSi(_5834);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _target;
    ((int *)_2)[2] = _source;
    _5834 = MAKE_SEQ(_1);
    RefDS(_5842);
    RefDS(_5834);
    _16c_stmt(_5842, _5834);
L6:
L3:

    // end procedure
    DeRef(_5834);
    return 0;
    ;
}


int _18seg_poke1(int _source, int _dbl)
{
    int _5844;
    int _5846;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_source)) {
        _1 = (long)(DBL_PTR(_source)->dbl);
        DeRefDS(_source);
        _source = _1;
    }
    if (!IS_ATOM_INT(_dbl)) {
        _1 = (long)(DBL_PTR(_dbl)->dbl);
        DeRefDS(_dbl);
        _dbl = _1;
    }

    //     if atom(dj_path) then
    _5844 = IS_ATOM(_4dj_path);
    if (_5844 == 0)
        goto L1;

    // 	if dbl then
    if (_dbl == 0)
        goto L2;

    // 	    if EWINDOWS and atom(bor_path) and atom(wat_path) then
    if (_4EWINDOWS == 0) {
        _5844 = 0;
        goto L3;
    }
    _5846 = IS_ATOM(_4bor_path);
    _5844 = (_5846 != 0);
L3:
    if (_5844 == 0) {
        goto L4;
    }
    _5844 = IS_ATOM(_4wat_path);
L5:
    if (_5844 == 0)
        goto L4;

    // 		c_stmt("_1 = (signed char)DBL_PTR(@)->dbl;\n", source)
    RefDS(_5849);
    _16c_stmt(_5849, _source);

    // 		c_stmt0("*poke_addr = _1;\n")
    RefDS(_5850);
    _16c_stmt0(_5850);
    goto L6;
L4:

    // 		c_stmt("*poke_addr = (signed char)DBL_PTR(@)->dbl;\n", source)
    RefDS(_5851);
    _16c_stmt(_5851, _source);
L7:
    goto L6;
L2:

    // 	    c_stmt("*poke_addr = (unsigned char)@;\n", source)
    RefDS(_5852);
    _16c_stmt(_5852, _source);
L8:
    goto L6;
L1:

    // 	if dbl then
    if (_dbl == 0)
        goto L9;

    // 	    c_stmt0("if ((unsigned)poke_addr > LOW_MEMORY_MAX)\n")
    RefDS(_5853);
    _16c_stmt0(_5853);

    // 	    c_stmt("*poke_addr = (signed char)DBL_PTR(@)->dbl;\n", source)
    RefDS(_5851);
    _16c_stmt(_5851, _source);

    // 	    c_stmt0("else\n")
    RefDS(_5799);
    _16c_stmt0(_5799);

    // 	    c_stmt("_farpokeb(_go32_info_block.selector_for_linear_memory, (unsigned long)poke_addr, (unsigned char)DBL_PTR(@)->dbl);\n", 
    RefDS(_5854);
    _16c_stmt(_5854, _source);
    goto LA;
L9:

    // 	    c_stmt0("if ((unsigned)poke_addr > LOW_MEMORY_MAX)\n")
    RefDS(_5853);
    _16c_stmt0(_5853);

    // 	    c_stmt("*poke_addr = (unsigned char)@;\n", source)
    RefDS(_5852);
    _16c_stmt(_5852, _source);

    // 	    c_stmt0("else\n")
    RefDS(_5799);
    _16c_stmt0(_5799);

    // 	    c_stmt("_farpokeb(_go32_info_block.selector_for_linear_memory, (unsigned long)poke_addr, (unsigned char)@);\n", 
    RefDS(_5855);
    _16c_stmt(_5855, _source);
LA:
L6:

    // end procedure
    return 0;
    ;
}


int _18seg_poke4(int _source, int _dbl)
{
    int _5856;
    int _5858;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_source)) {
        _1 = (long)(DBL_PTR(_source)->dbl);
        DeRefDS(_source);
        _source = _1;
    }
    if (!IS_ATOM_INT(_dbl)) {
        _1 = (long)(DBL_PTR(_dbl)->dbl);
        DeRefDS(_dbl);
        _dbl = _1;
    }

    //     if atom(dj_path) then
    _5856 = IS_ATOM(_4dj_path);
    if (_5856 == 0)
        goto L1;

    // 	if dbl then
    if (_dbl == 0)
        goto L2;

    // 	    if EWINDOWS and atom(bor_path) and atom(wat_path) then
    if (_4EWINDOWS == 0) {
        _5856 = 0;
        goto L3;
    }
    _5858 = IS_ATOM(_4bor_path);
    _5856 = (_5858 != 0);
L3:
    if (_5856 == 0) {
        goto L4;
    }
    _5856 = IS_ATOM(_4wat_path);
L5:
    if (_5856 == 0)
        goto L4;

    // 		c_stmt("_1 = (unsigned long)DBL_PTR(@)->dbl;\n", source)
    RefDS(_5861);
    _16c_stmt(_5861, _source);

    // 		c_stmt0("*poke4_addr = (unsigned long)_1;\n")
    RefDS(_5862);
    _16c_stmt0(_5862);
    goto L6;
L4:

    // 		c_stmt("*poke4_addr = (unsigned long)DBL_PTR(@)->dbl;\n", source)
    RefDS(_5863);
    _16c_stmt(_5863, _source);
L7:
    goto L6;
L2:

    // 	    c_stmt("*poke4_addr = (unsigned long)@;\n", source)
    RefDS(_5864);
    _16c_stmt(_5864, _source);
L8:
    goto L6;
L1:

    // 	if dbl then
    if (_dbl == 0)
        goto L9;

    // 	    c_stmt0("if ((unsigned)poke4_addr > LOW_MEMORY_MAX)\n")
    RefDS(_5865);
    _16c_stmt0(_5865);

    // 	    c_stmt("*poke4_addr = (unsigned long)DBL_PTR(@)->dbl;\n", source)
    RefDS(_5863);
    _16c_stmt(_5863, _source);

    // 	    c_stmt0("else\n")
    RefDS(_5799);
    _16c_stmt0(_5799);

    // 	    c_stmt("_farpokel(_go32_info_block.selector_for_linear_memory, (unsigned long)poke4_addr, (unsigned long)DBL_PTR(@)->dbl);\n", 
    RefDS(_5866);
    _16c_stmt(_5866, _source);
    goto LA;
L9:

    // 	    c_stmt0("if ((unsigned)poke4_addr > LOW_MEMORY_MAX)\n")
    RefDS(_5865);
    _16c_stmt0(_5865);

    // 	    c_stmt("*poke4_addr = (unsigned long)@;\n", source)
    RefDS(_5864);
    _16c_stmt(_5864, _source);

    // 	    c_stmt0("else\n")
    RefDS(_5799);
    _16c_stmt0(_5799);

    // 	    c_stmt("_farpokel(_go32_info_block.selector_for_linear_memory, (unsigned long)poke4_addr, (unsigned long)@);\n", 
    RefDS(_5867);
    _16c_stmt(_5867, _source);
LA:
L6:

    // end procedure
    return 0;
    ;
}


int _18machine_func_type(int _x)
{
    int _s;
    int _func_num;
    int _range = 0;
    int _5868 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_x)) {
        _1 = (long)(DBL_PTR(_x)->dbl);
        DeRefDS(_x);
        _x = _1;
    }

    //     s = x
    _s = _x;

    //     if SymTab[s][S_MODE] = M_CONSTANT then
    _2 = (int)SEQ_PTR(_4SymTab);
    _5868 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5868);
    _0 = _5868;
    _2 = (int)SEQ_PTR(_5868);
    _5868 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_5868);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _5868, 2))
        goto L1;

    // 	if GType(x) = TYPE_INTEGER then
    _0 = _5868;
    _5868 = _16GType(_x);
    DeRef(_0);
    if (_5868 != 1)
        goto L2;

    // 	    func_num = ObjValue(x)
    _func_num = _16ObjValue(_x);
    if (!IS_ATOM_INT(_func_num)) {
        _1 = (long)(DBL_PTR(_func_num)->dbl);
        DeRefDS(_func_num);
        _func_num = _1;
    }

    // 	    if func_num != NOVALUE then
    if (binary_op_a(EQUALS, _func_num, _4NOVALUE))
        goto L3;

    // 		if func_num = M_COMPLETE then 
    if (_func_num != 0)
        goto L4;

    // 		    range = {MININT, MAXINT}
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -1073741824;
    ((int *)_2)[2] = 1073741823;
    _range = MAKE_SEQ(_1);

    // 		    return {TYPE_INTEGER, range}
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = _range;
    RefDS(_range);
    _5868 = MAKE_SEQ(_1);
    DeRefDSi(_range);
    return _5868;
    goto L5;
L4:

    // 		elsif func_num = M_GRAPHICS_MODE then
    if (_func_num != 5)
        goto L6;

    // 		    range = {MININT, MAXINT}
    DeRefi(_range);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -1073741824;
    ((int *)_2)[2] = 1073741823;
    _range = MAKE_SEQ(_1);

    // 		    return {TYPE_INTEGER, range}
    DeRef(_5868);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = _range;
    RefDS(_range);
    _5868 = MAKE_SEQ(_1);
    DeRefDSi(_range);
    return _5868;
    goto L5;
L6:

    // 		elsif func_num = M_TEXTROWS then
    if (_func_num != 12)
        goto L7;

    // 		    range = {20, 500}
    DeRefi(_range);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 20;
    ((int *)_2)[2] = 500;
    _range = MAKE_SEQ(_1);

    // 		    return {TYPE_INTEGER, range}
    DeRef(_5868);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = _range;
    RefDS(_range);
    _5868 = MAKE_SEQ(_1);
    DeRefDSi(_range);
    return _5868;
    goto L5;
L7:

    // 		elsif func_num = M_SEEK then
    if (_func_num != 19)
        goto L8;

    // 		    range = {MININT, MAXINT}
    DeRefi(_range);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -1073741824;
    ((int *)_2)[2] = 1073741823;
    _range = MAKE_SEQ(_1);

    // 		    return {TYPE_INTEGER, range}
    DeRef(_5868);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = _range;
    RefDS(_range);
    _5868 = MAKE_SEQ(_1);
    DeRefDSi(_range);
    return _5868;
    goto L5;
L8:

    // 		elsif func_num = M_LOCK_FILE then
    if (_func_num != 61)
        goto L9;

    // 		    range = {0, 1}
    DeRefi(_range);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 1;
    _range = MAKE_SEQ(_1);

    // 		    return {TYPE_INTEGER, range}
    DeRef(_5868);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = _range;
    RefDS(_range);
    _5868 = MAKE_SEQ(_1);
    DeRefDSi(_range);
    return _5868;
    goto L5;
L9:

    // 		elsif func_num = M_CHDIR then
    if (_func_num != 63)
        goto LA;

    // 		    range = {0, 1}
    DeRefi(_range);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 1;
    _range = MAKE_SEQ(_1);

    // 		    return {TYPE_INTEGER, range}
    DeRef(_5868);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = _range;
    RefDS(_range);
    _5868 = MAKE_SEQ(_1);
    DeRefDSi(_range);
    return _5868;
    goto L5;
LA:

    // 		elsif func_num = M_CHECK_BREAK then
    if (_func_num != 43)
        goto LB;

    // 		    range = {0, MAXINT-1000}
    DeRef(_5868);
    _5868 = 1073740823;
    DeRefi(_range);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 1073740823;
    _range = MAKE_SEQ(_1);

    // 		    return {TYPE_INTEGER, range}
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = _range;
    RefDS(_range);
    _5868 = MAKE_SEQ(_1);
    DeRefDSi(_range);
    return _5868;
    goto L5;
LB:

    // 		elsif func_num = M_GET_DISPLAY_PAGE then
    if (_func_num != 28)
        goto LC;

    // 		    range = {0, 64}
    DeRefi(_range);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 64;
    _range = MAKE_SEQ(_1);

    // 		    return {TYPE_INTEGER, range}
    DeRef(_5868);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = _range;
    RefDS(_range);
    _5868 = MAKE_SEQ(_1);
    DeRefDSi(_range);
    return _5868;
    goto L5;
LC:

    // 		elsif func_num = M_GET_ACTIVE_PAGE then
    if (_func_num != 30)
        goto LD;

    // 		    range = {0, 64}
    DeRefi(_range);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 64;
    _range = MAKE_SEQ(_1);

    // 		    return {TYPE_INTEGER, range}
    DeRef(_5868);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = _range;
    RefDS(_range);
    _5868 = MAKE_SEQ(_1);
    DeRefDSi(_range);
    return _5868;
    goto L5;
LD:

    // 		elsif func_num = M_ALLOC_LOW then
    if (_func_num != 32)
        goto LE;

    // 		    range = {0, 1500000}
    DeRefi(_range);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 1500000;
    _range = MAKE_SEQ(_1);

    // 		    return {TYPE_INTEGER, range}
    DeRef(_5868);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = _range;
    RefDS(_range);
    _5868 = MAKE_SEQ(_1);
    DeRefDSi(_range);
    return _5868;
    goto L5;
LE:

    // 		elsif func_num = M_DEFINE_C then
    if (_func_num != 51)
        goto LF;

    // 		    range = {-1, 100000000}
    DeRefi(_range);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -1;
    ((int *)_2)[2] = 100000000;
    _range = MAKE_SEQ(_1);

    // 		    return {TYPE_INTEGER, range}
    DeRef(_5868);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = _range;
    RefDS(_range);
    _5868 = MAKE_SEQ(_1);
    DeRefDSi(_range);
    return _5868;
    goto L5;
LF:

    // 		elsif func_num = M_WAIT_KEY then
    if (_func_num != 26)
        goto L10;

    // 		    range = {-1, 1000}
    DeRefi(_range);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -1;
    ((int *)_2)[2] = 1000;
    _range = MAKE_SEQ(_1);

    // 		    return {TYPE_INTEGER, range}
    DeRef(_5868);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = _range;
    RefDS(_range);
    _5868 = MAKE_SEQ(_1);
    DeRefDSi(_range);
    return _5868;
    goto L5;
L10:

    // 		elsif find(func_num, {M_WHERE, M_OPEN_DLL, M_CALLBACK,
    DeRef(_5868);
    _5868 = find(_func_num, _5914);
    if (_5868 == 0)
        goto L11;

    // 		    return {TYPE_ATOM, novalue}
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 4;
    ((int *)_2)[2] = _9novalue;
    RefDS(_9novalue);
    _5868 = MAKE_SEQ(_1);
    DeRefi(_range);
    return _5868;
    goto L5;
L11:

    // 		elsif find(func_num, {M_VIDEO_CONFIG, M_GET_POSITION,
    DeRef(_5868);
    _5868 = find(_func_num, _5917);
    if (_5868 == 0)
        goto L12;

    // 		    return {TYPE_SEQUENCE, novalue}
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 8;
    ((int *)_2)[2] = _9novalue;
    RefDS(_9novalue);
    _5868 = MAKE_SEQ(_1);
    DeRefi(_range);
    return _5868;
    goto L5;
L12:

    // 		    return {TYPE_OBJECT, novalue}
    DeRef(_5868);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 16;
    ((int *)_2)[2] = _9novalue;
    RefDS(_9novalue);
    _5868 = MAKE_SEQ(_1);
    DeRefi(_range);
    return _5868;
L5:
L3:
L2:
L1:

    //     return {TYPE_OBJECT, novalue}
    DeRef(_5868);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 16;
    ((int *)_2)[2] = _9novalue;
    RefDS(_9novalue);
    _5868 = MAKE_SEQ(_1);
    DeRefi(_range);
    return _5868;
    ;
}


int _18machine_func_elem_type(int _x)
{
    int _s;
    int _func_num;
    int _5922 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_x)) {
        _1 = (long)(DBL_PTR(_x)->dbl);
        DeRefDS(_x);
        _x = _1;
    }

    //     s = x
    _s = _x;

    //     if SymTab[s][S_MODE] = M_CONSTANT then
    _2 = (int)SEQ_PTR(_4SymTab);
    _5922 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5922);
    _0 = _5922;
    _2 = (int)SEQ_PTR(_5922);
    _5922 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_5922);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _5922, 2))
        goto L1;

    // 	if GType(x) = TYPE_INTEGER then
    _0 = _5922;
    _5922 = _16GType(_x);
    DeRef(_0);
    if (_5922 != 1)
        goto L2;

    // 	    func_num = ObjValue(x)
    _func_num = _16ObjValue(_x);
    if (!IS_ATOM_INT(_func_num)) {
        _1 = (long)(DBL_PTR(_func_num)->dbl);
        DeRefDS(_func_num);
        _func_num = _1;
    }

    // 	    if func_num != NOVALUE then
    if (binary_op_a(EQUALS, _func_num, _4NOVALUE))
        goto L3;

    // 		if find(func_num, {M_VIDEO_CONFIG, M_GET_POSITION, 
    _5922 = find(_func_num, _5929);
    if (_5922 == 0)
        goto L4;

    // 			return TYPE_INTEGER
    return 1;
    goto L5;
L4:

    // 		    return TYPE_OBJECT
    DeRef(_5922);
    return 16;
L5:
L3:
L2:
L1:

    //     return TYPE_OBJECT
    DeRef(_5922);
    return 16;
    ;
}


int _18main_temps()
{
    int _sp;
    int _5951 = 0;
    int _5931 = 0;
    int _0, _1, _2, _3;
    

    //     NewBB(0, E_ALL_EFFECT, 0)
    _16NewBB(0, 1073741823, 0);

    //     sp = SymTab[TopLevelSub][S_TEMPS]
    _2 = (int)SEQ_PTR(_4SymTab);
    _5931 = (int)*(((s1_ptr)_2)->base + _4TopLevelSub);
    RefDS(_5931);
    _2 = (int)SEQ_PTR(_5931);
    _sp = (int)*(((s1_ptr)_2)->base + 18);
    if (!IS_ATOM_INT(_sp))
        _sp = (long)DBL_PTR(_sp)->dbl;

    //     while sp != 0 do
L1:
    if (_sp == 0)
        goto L2;

    // 	if SymTab[sp][S_SCOPE] != DELETED then
    DeRef(_5931);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5931 = (int)*(((s1_ptr)_2)->base + _sp);
    RefDS(_5931);
    _0 = _5931;
    _2 = (int)SEQ_PTR(_5931);
    _5931 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_5931);
    DeRefDS(_0);
    if (binary_op_a(EQUALS, _5931, 2))
        goto L3;

    // 	    if temp_name_type[SymTab[sp][S_TEMP_NAME]][T_GTYPE] != TYPE_NULL then
    DeRef(_5931);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5931 = (int)*(((s1_ptr)_2)->base + _sp);
    RefDS(_5931);
    _0 = _5931;
    _2 = (int)SEQ_PTR(_5931);
    _5931 = (int)*(((s1_ptr)_2)->base + 31);
    Ref(_5931);
    DeRefDS(_0);
    _0 = _5931;
    _2 = (int)SEQ_PTR(_4temp_name_type);
    if (!IS_ATOM_INT(_5931))
        _5931 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5931)->dbl));
    else
        _5931 = (int)*(((s1_ptr)_2)->base + _5931);
    RefDS(_5931);
    DeRef(_0);
    _0 = _5931;
    _2 = (int)SEQ_PTR(_5931);
    _5931 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5931);
    DeRefDS(_0);
    if (binary_op_a(EQUALS, _5931, 0))
        goto L4;

    // 		c_stmt0("int ")
    RefDS(_4457);
    _16c_stmt0(_4457);

    // 		c_printf("_%d", SymTab[sp][S_TEMP_NAME])
    DeRef(_5931);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5931 = (int)*(((s1_ptr)_2)->base + _sp);
    RefDS(_5931);
    _0 = _5931;
    _2 = (int)SEQ_PTR(_5931);
    _5931 = (int)*(((s1_ptr)_2)->base + 31);
    Ref(_5931);
    DeRefDS(_0);
    RefDS(_4345);
    Ref(_5931);
    _9c_printf(_4345, _5931);

    // 		if temp_name_type[SymTab[sp][S_TEMP_NAME]][T_GTYPE] != TYPE_INTEGER then
    DeRef(_5931);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5931 = (int)*(((s1_ptr)_2)->base + _sp);
    RefDS(_5931);
    _0 = _5931;
    _2 = (int)SEQ_PTR(_5931);
    _5931 = (int)*(((s1_ptr)_2)->base + 31);
    Ref(_5931);
    DeRefDS(_0);
    _0 = _5931;
    _2 = (int)SEQ_PTR(_4temp_name_type);
    if (!IS_ATOM_INT(_5931))
        _5931 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5931)->dbl));
    else
        _5931 = (int)*(((s1_ptr)_2)->base + _5931);
    RefDS(_5931);
    DeRef(_0);
    _0 = _5931;
    _2 = (int)SEQ_PTR(_5931);
    _5931 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5931);
    DeRefDS(_0);
    if (binary_op_a(EQUALS, _5931, 1))
        goto L5;

    // 		    c_puts(" = 0")
    RefDS(_5180);
    _9c_puts(_5180);

    // 		    target = {0, 0}
    DeRef(_18target);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 0;
    _18target = MAKE_SEQ(_1);

    // 		    SetBBType(sp, TYPE_INTEGER, target, TYPE_OBJECT)
    RefDS(_18target);
    _16SetBBType(_sp, 1, _18target, 16);
L5:

    // 		c_puts(";\n")
    RefDS(_4460);
    _9c_puts(_4460);
L4:
L3:

    // 	SymTab[sp][S_GTYPE] = TYPE_OBJECT
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sp + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 26);
    _1 = *(int *)_2;
    *(int *)_2 = 16;
    DeRef(_1);

    // 	sp = SymTab[sp][S_NEXT]
    DeRef(_5951);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5951 = (int)*(((s1_ptr)_2)->base + _sp);
    RefDS(_5951);
    _2 = (int)SEQ_PTR(_5951);
    _sp = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_sp))
        _sp = (long)DBL_PTR(_sp)->dbl;

    //     end while
    goto L1;
L2:

    //     if SymTab[TopLevelSub][S_LHS_SUBS2] then
    DeRef(_5951);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5951 = (int)*(((s1_ptr)_2)->base + _4TopLevelSub);
    RefDS(_5951);
    _0 = _5951;
    _2 = (int)SEQ_PTR(_5951);
    _5951 = (int)*(((s1_ptr)_2)->base + 34);
    Ref(_5951);
    DeRefDS(_0);
    if (_5951 == 0) {
        goto L6;
    }
    else {
        if (!IS_ATOM_INT(_5951) && DBL_PTR(_5951)->dbl == 0.0)
            goto L6;
    }

    // 	c_stmt0("int _0, _1, _2, _3;\n\n")
    RefDS(_5208);
    _16c_stmt0(_5208);
    goto L7;
L6:

    // 	c_stmt0("int _0, _1, _2;\n\n")
    RefDS(_5209);
    _16c_stmt0(_5209);
L7:

    // end procedure
    DeRef(_5951);
    DeRef(_5931);
    return 0;
    ;
}


int _18FoldInteger(int _op, int _target, int _left, int _right)
{
    int _left_val = 0;
    int _right_val = 0;
    int _result = 0;
    int _intres = 0;
    int _d1 = 0;
    int _d2 = 0;
    int _d3 = 0;
    int _d4 = 0;
    int _p1 = 0;
    int _p2 = 0;
    int _p3 = 0;
    int _p4 = 0;
    int _6057 = 0;
    int _5956 = 0;
    int _5961 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_op)) {
        _1 = (long)(DBL_PTR(_op)->dbl);
        DeRefDS(_op);
        _op = _1;
    }
    if (!IS_ATOM_INT(_target)) {
        _1 = (long)(DBL_PTR(_target)->dbl);
        DeRefDS(_target);
        _target = _1;
    }
    if (!IS_ATOM_INT(_left)) {
        _1 = (long)(DBL_PTR(_left)->dbl);
        DeRefDS(_left);
        _left = _1;
    }
    if (!IS_ATOM_INT(_right)) {
        _1 = (long)(DBL_PTR(_right)->dbl);
        DeRefDS(_right);
        _right = _1;
    }

    //     left_val = ObjMinMax(left)
    _left_val = _18ObjMinMax(_left);

    //     right_val = ObjMinMax(right)
    _right_val = _18ObjMinMax(_right);

    //     result = {NOVALUE, NOVALUE}
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _4NOVALUE;
    RefDS(_4NOVALUE);
    ((int *)_2)[2] = _4NOVALUE;
    RefDS(_4NOVALUE);
    _result = MAKE_SEQ(_1);

    //     if op = PLUS or op = PLUS_I then
    _5956 = (_op == 11);
    if (_5956 != 0) {
        goto L1;
    }
    _5961 = (_op == 115);
L2:
    if (_5961 == 0)
        goto L3;
L1:

    // 	intres = left_val[MIN] + right_val[MIN]
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_left_val);
    _5961 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5961);
    DeRef(_5956);
    _2 = (int)SEQ_PTR(_right_val);
    _5956 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5956);
    DeRef(_intres);
    if (IS_ATOM_INT(_5961) && IS_ATOM_INT(_5956)) {
        _intres = _5961 + _5956;
        if ((long)((unsigned long)_intres + (unsigned long)HIGH_BITS) >= 0) 
            _intres = NewDouble((double)_intres);
    }
    else {
        _intres = binary_op(PLUS, _5961, _5956);
    }

    // 	if intres >= MININT and intres <= MAXINT then
    DeRef(_5956);
    if (IS_ATOM_INT(_intres)) {
        _5956 = (_intres >= -1073741824);
    }
    else {
        _5956 = (DBL_PTR(_intres)->dbl >= (double)-1073741824);
    }
    if (_5956 == 0) {
        goto L4;
    }
    DeRef(_5961);
    if (IS_ATOM_INT(_intres)) {
        _5961 = (_intres <= 1073741823);
    }
    else {
        _5961 = (DBL_PTR(_intres)->dbl <= (double)1073741823);
    }
L5:
    if (_5961 == 0)
        goto L4;

    // 	    result[MIN] = intres
    Ref(_intres);
    _2 = (int)SEQ_PTR(_result);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _result = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _intres;
    DeRef(_1);
    goto L6;
L4:

    // 	    result[MIN] = NOVALUE
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(_result);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _result = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);
L6:

    // 	intres = left_val[MAX] + right_val[MAX]
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_left_val);
    _5961 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5961);
    DeRef(_5956);
    _2 = (int)SEQ_PTR(_right_val);
    _5956 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5956);
    DeRef(_intres);
    if (IS_ATOM_INT(_5961) && IS_ATOM_INT(_5956)) {
        _intres = _5961 + _5956;
        if ((long)((unsigned long)_intres + (unsigned long)HIGH_BITS) >= 0) 
            _intres = NewDouble((double)_intres);
    }
    else {
        _intres = binary_op(PLUS, _5961, _5956);
    }

    // 	if intres >= MININT and intres <= MAXINT then
    DeRef(_5956);
    if (IS_ATOM_INT(_intres)) {
        _5956 = (_intres >= -1073741824);
    }
    else {
        _5956 = (DBL_PTR(_intres)->dbl >= (double)-1073741824);
    }
    if (_5956 == 0) {
        goto L7;
    }
    DeRef(_5961);
    if (IS_ATOM_INT(_intres)) {
        _5961 = (_intres <= 1073741823);
    }
    else {
        _5961 = (DBL_PTR(_intres)->dbl <= (double)1073741823);
    }
L8:
    if (_5961 == 0)
        goto L7;

    // 	    result[MAX] = intres
    Ref(_intres);
    _2 = (int)SEQ_PTR(_result);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _result = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _intres;
    DeRef(_1);
    goto L9;
L7:

    // 	    result[MIN] = NOVALUE
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(_result);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _result = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);
L9:

    // 	if result[MIN] = result[MAX] and result[MIN] != NOVALUE then
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_result);
    _5961 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5961);
    DeRef(_5956);
    _2 = (int)SEQ_PTR(_result);
    _5956 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5956);
    _0 = _5956;
    if (IS_ATOM_INT(_5961) && IS_ATOM_INT(_5956)) {
        _5956 = (_5961 == _5956);
    }
    else {
        _5956 = binary_op(EQUALS, _5961, _5956);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_5956)) {
        if (_5956 == 0) {
            goto LA;
        }
    }
    else {
        if (DBL_PTR(_5956)->dbl == 0.0) {
            goto LA;
        }
    }
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_result);
    _5961 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5961);
    _0 = _5961;
    _5961 = binary_op(NOTEQ, _5961, _4NOVALUE);
    DeRef(_0);
LB:
    if (_5961 == 0) {
        goto LA;
    }
    else {
        if (!IS_ATOM_INT(_5961) && DBL_PTR(_5961)->dbl == 0.0)
            goto LA;
    }

    // 	    c_stmt("@ = ", target)
    RefDS(_5789);
    _16c_stmt(_5789, _target);

    // 	    c_printf("%d;\n", result[MIN])
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_result);
    _5961 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5961);
    RefDS(_5980);
    Ref(_5961);
    _9c_printf(_5980, _5961);
LC:
    goto LA;
L3:

    //     elsif op = MINUS or op = MINUS_I then
    DeRef(_5961);
    _5961 = (_op == 10);
    if (_5961 != 0) {
        goto LD;
    }
    DeRef(_5956);
    _5956 = (_op == 116);
LE:
    if (_5956 == 0)
        goto LF;
LD:

    // 	intres = left_val[MIN] - right_val[MAX]
    DeRef(_5956);
    _2 = (int)SEQ_PTR(_left_val);
    _5956 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5956);
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_right_val);
    _5961 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5961);
    DeRef(_intres);
    if (IS_ATOM_INT(_5956) && IS_ATOM_INT(_5961)) {
        _intres = _5956 - _5961;
        if ((long)((unsigned long)_intres +(unsigned long) HIGH_BITS) >= 0)
            _intres = NewDouble((double)_intres);
    }
    else {
        _intres = binary_op(MINUS, _5956, _5961);
    }

    // 	if intres >= MININT and intres <= MAXINT then
    DeRef(_5961);
    if (IS_ATOM_INT(_intres)) {
        _5961 = (_intres >= -1073741824);
    }
    else {
        _5961 = (DBL_PTR(_intres)->dbl >= (double)-1073741824);
    }
    if (_5961 == 0) {
        goto L10;
    }
    DeRef(_5956);
    if (IS_ATOM_INT(_intres)) {
        _5956 = (_intres <= 1073741823);
    }
    else {
        _5956 = (DBL_PTR(_intres)->dbl <= (double)1073741823);
    }
L11:
    if (_5956 == 0)
        goto L10;

    // 	    result[MIN] = intres
    Ref(_intres);
    _2 = (int)SEQ_PTR(_result);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _result = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _intres;
    DeRef(_1);
    goto L12;
L10:

    // 	    result[MIN] = NOVALUE
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(_result);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _result = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);
L12:

    // 	intres = left_val[MAX] - right_val[MIN]
    DeRef(_5956);
    _2 = (int)SEQ_PTR(_left_val);
    _5956 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5956);
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_right_val);
    _5961 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5961);
    DeRef(_intres);
    if (IS_ATOM_INT(_5956) && IS_ATOM_INT(_5961)) {
        _intres = _5956 - _5961;
        if ((long)((unsigned long)_intres +(unsigned long) HIGH_BITS) >= 0)
            _intres = NewDouble((double)_intres);
    }
    else {
        _intres = binary_op(MINUS, _5956, _5961);
    }

    // 	if intres >= MININT and intres <= MAXINT then
    DeRef(_5961);
    if (IS_ATOM_INT(_intres)) {
        _5961 = (_intres >= -1073741824);
    }
    else {
        _5961 = (DBL_PTR(_intres)->dbl >= (double)-1073741824);
    }
    if (_5961 == 0) {
        goto L13;
    }
    DeRef(_5956);
    if (IS_ATOM_INT(_intres)) {
        _5956 = (_intres <= 1073741823);
    }
    else {
        _5956 = (DBL_PTR(_intres)->dbl <= (double)1073741823);
    }
L14:
    if (_5956 == 0)
        goto L13;

    // 	    result[MAX] = intres
    Ref(_intres);
    _2 = (int)SEQ_PTR(_result);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _result = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _intres;
    DeRef(_1);
    goto L15;
L13:

    // 	    result[MIN] = NOVALUE
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(_result);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _result = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);
L15:

    // 	if result[MIN] = result[MAX] and result[MIN] != NOVALUE then
    DeRef(_5956);
    _2 = (int)SEQ_PTR(_result);
    _5956 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5956);
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_result);
    _5961 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5961);
    _0 = _5961;
    if (IS_ATOM_INT(_5956) && IS_ATOM_INT(_5961)) {
        _5961 = (_5956 == _5961);
    }
    else {
        _5961 = binary_op(EQUALS, _5956, _5961);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_5961)) {
        if (_5961 == 0) {
            goto LA;
        }
    }
    else {
        if (DBL_PTR(_5961)->dbl == 0.0) {
            goto LA;
        }
    }
    DeRef(_5956);
    _2 = (int)SEQ_PTR(_result);
    _5956 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5956);
    _0 = _5956;
    _5956 = binary_op(NOTEQ, _5956, _4NOVALUE);
    DeRef(_0);
L16:
    if (_5956 == 0) {
        goto LA;
    }
    else {
        if (!IS_ATOM_INT(_5956) && DBL_PTR(_5956)->dbl == 0.0)
            goto LA;
    }

    // 	    c_stmt("@ = ", target)
    RefDS(_5789);
    _16c_stmt(_5789, _target);

    // 	    c_printf("%d;\n", result[MIN])
    DeRef(_5956);
    _2 = (int)SEQ_PTR(_result);
    _5956 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5956);
    RefDS(_5980);
    Ref(_5956);
    _9c_printf(_5980, _5956);
L17:
    goto LA;
LF:

    //     elsif op = MULTIPLY then
    if (_op != 13)
        goto L18;

    // 	d1 = left_val[MIN] * right_val[MIN]
    DeRef(_5956);
    _2 = (int)SEQ_PTR(_left_val);
    _5956 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5956);
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_right_val);
    _5961 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5961);
    DeRef(_d1);
    if (IS_ATOM_INT(_5956) && IS_ATOM_INT(_5961)) {
        if (_5956 == (short)_5956 && _5961 <= INT15 && _5961 >= -INT15)
            _d1 = _5956 * _5961;
        else
            _d1 = NewDouble(_5956 * (double)_5961);
    }
    else {
        _d1 = binary_op(MULTIPLY, _5956, _5961);
    }

    // 	d2 = left_val[MIN] * right_val[MAX]
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_left_val);
    _5961 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5961);
    DeRef(_5956);
    _2 = (int)SEQ_PTR(_right_val);
    _5956 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5956);
    DeRef(_d2);
    if (IS_ATOM_INT(_5961) && IS_ATOM_INT(_5956)) {
        if (_5961 == (short)_5961 && _5956 <= INT15 && _5956 >= -INT15)
            _d2 = _5961 * _5956;
        else
            _d2 = NewDouble(_5961 * (double)_5956);
    }
    else {
        _d2 = binary_op(MULTIPLY, _5961, _5956);
    }

    // 	d3 = left_val[MAX] * right_val[MIN]
    DeRef(_5956);
    _2 = (int)SEQ_PTR(_left_val);
    _5956 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5956);
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_right_val);
    _5961 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5961);
    DeRef(_d3);
    if (IS_ATOM_INT(_5956) && IS_ATOM_INT(_5961)) {
        if (_5956 == (short)_5956 && _5961 <= INT15 && _5961 >= -INT15)
            _d3 = _5956 * _5961;
        else
            _d3 = NewDouble(_5956 * (double)_5961);
    }
    else {
        _d3 = binary_op(MULTIPLY, _5956, _5961);
    }

    // 	d4 = left_val[MAX] * right_val[MAX]
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_left_val);
    _5961 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5961);
    DeRef(_5956);
    _2 = (int)SEQ_PTR(_right_val);
    _5956 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5956);
    DeRef(_d4);
    if (IS_ATOM_INT(_5961) && IS_ATOM_INT(_5956)) {
        if (_5961 == (short)_5961 && _5956 <= INT15 && _5956 >= -INT15)
            _d4 = _5961 * _5956;
        else
            _d4 = NewDouble(_5961 * (double)_5956);
    }
    else {
        _d4 = binary_op(MULTIPLY, _5961, _5956);
    }

    // 	if d1 <= MAXINT_DBL and d1 >= MININT_DBL and
    DeRef(_5956);
    if (IS_ATOM_INT(_d1)) {
        _5956 = (_d1 <= 1073741823);
    }
    else {
        _5956 = (DBL_PTR(_d1)->dbl <= (double)1073741823);
    }
    if (_5956 == 0) {
        _5956 = 0;
        goto L19;
    }
    DeRef(_5961);
    if (IS_ATOM_INT(_d1)) {
        _5961 = (_d1 >= -1073741824);
    }
    else {
        _5961 = (DBL_PTR(_d1)->dbl >= (double)-1073741824);
    }
    _5956 = (_5961 != 0);
L19:
    if (_5956 == 0) {
        DeRef(_5961);
        _5961 = 0;
        goto L1A;
    }
    DeRef(_5956);
    if (IS_ATOM_INT(_d2)) {
        _5956 = (_d2 <= 1073741823);
    }
    else {
        _5956 = (DBL_PTR(_d2)->dbl <= (double)1073741823);
    }
    _5961 = (_5956 != 0);
L1A:
    if (_5961 == 0) {
        DeRef(_5956);
        _5956 = 0;
        goto L1B;
    }
    DeRef(_5961);
    if (IS_ATOM_INT(_d2)) {
        _5961 = (_d2 >= -1073741824);
    }
    else {
        _5961 = (DBL_PTR(_d2)->dbl >= (double)-1073741824);
    }
    _5956 = (_5961 != 0);
L1B:
    if (_5956 == 0) {
        DeRef(_5961);
        _5961 = 0;
        goto L1C;
    }
    DeRef(_5956);
    if (IS_ATOM_INT(_d3)) {
        _5956 = (_d3 <= 1073741823);
    }
    else {
        _5956 = (DBL_PTR(_d3)->dbl <= (double)1073741823);
    }
    _5961 = (_5956 != 0);
L1C:
    if (_5961 == 0) {
        DeRef(_5956);
        _5956 = 0;
        goto L1D;
    }
    DeRef(_5961);
    if (IS_ATOM_INT(_d3)) {
        _5961 = (_d3 >= -1073741824);
    }
    else {
        _5961 = (DBL_PTR(_d3)->dbl >= (double)-1073741824);
    }
    _5956 = (_5961 != 0);
L1D:
    if (_5956 == 0) {
        DeRef(_5961);
        _5961 = 0;
        goto L1E;
    }
    DeRef(_5956);
    if (IS_ATOM_INT(_d4)) {
        _5956 = (_d4 <= 1073741823);
    }
    else {
        _5956 = (DBL_PTR(_d4)->dbl <= (double)1073741823);
    }
    _5961 = (_5956 != 0);
L1E:
    if (_5961 == 0) {
        goto LA;
    }
    DeRef(_5961);
    if (IS_ATOM_INT(_d4)) {
        _5961 = (_d4 >= -1073741824);
    }
    else {
        _5961 = (DBL_PTR(_d4)->dbl >= (double)-1073741824);
    }
L1F:
    if (_5961 == 0)
        goto LA;

    // 	    p1 = d1
    Ref(_d1);
    DeRef(_p1);
    _p1 = _d1;

    // 	    p2 = d2
    Ref(_d2);
    DeRef(_p2);
    _p2 = _d2;

    // 	    p3 = d3
    Ref(_d3);
    DeRef(_p3);
    _p3 = _d3;

    // 	    p4 = d4
    Ref(_d4);
    DeRef(_p4);
    _p4 = _d4;

    // 	    result[MIN] = p1
    Ref(_p1);
    _2 = (int)SEQ_PTR(_result);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _result = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _p1;
    DeRef(_1);

    // 	    if p2 < result[MIN] then
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_result);
    _5961 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5961);
    if (binary_op_a(GREATEREQ, _p2, _5961))
        goto L20;

    // 		result[MIN] = p2
    Ref(_p2);
    _2 = (int)SEQ_PTR(_result);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _result = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _p2;
    DeRef(_1);
L20:

    // 	    if p3 < result[MIN] then
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_result);
    _5961 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5961);
    if (binary_op_a(GREATEREQ, _p3, _5961))
        goto L21;

    // 		result[MIN] = p3
    Ref(_p3);
    _2 = (int)SEQ_PTR(_result);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _result = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _p3;
    DeRef(_1);
L21:

    // 	    if p4 < result[MIN] then
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_result);
    _5961 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5961);
    if (binary_op_a(GREATEREQ, _p4, _5961))
        goto L22;

    // 		result[MIN] = p4
    Ref(_p4);
    _2 = (int)SEQ_PTR(_result);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _result = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _p4;
    DeRef(_1);
L22:

    // 	    result[MAX] = p1
    Ref(_p1);
    _2 = (int)SEQ_PTR(_result);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _result = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _p1;
    DeRef(_1);

    // 	    if p2 > result[MAX] then
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_result);
    _5961 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5961);
    if (binary_op_a(LESSEQ, _p2, _5961))
        goto L23;

    // 		result[MAX] = p2
    Ref(_p2);
    _2 = (int)SEQ_PTR(_result);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _result = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _p2;
    DeRef(_1);
L23:

    // 	    if p3 > result[MAX] then
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_result);
    _5961 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5961);
    if (binary_op_a(LESSEQ, _p3, _5961))
        goto L24;

    // 		result[MAX] = p3
    Ref(_p3);
    _2 = (int)SEQ_PTR(_result);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _result = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _p3;
    DeRef(_1);
L24:

    // 	    if p4 > result[MAX] then
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_result);
    _5961 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5961);
    if (binary_op_a(LESSEQ, _p4, _5961))
        goto L25;

    // 		result[MAX] = p4
    Ref(_p4);
    _2 = (int)SEQ_PTR(_result);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _result = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _p4;
    DeRef(_1);
L25:

    // 	    if result[MIN] = result[MAX] and result[MIN] != NOVALUE then
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_result);
    _5961 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5961);
    DeRef(_5956);
    _2 = (int)SEQ_PTR(_result);
    _5956 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5956);
    _0 = _5956;
    if (IS_ATOM_INT(_5961) && IS_ATOM_INT(_5956)) {
        _5956 = (_5961 == _5956);
    }
    else {
        _5956 = binary_op(EQUALS, _5961, _5956);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_5956)) {
        if (_5956 == 0) {
            goto LA;
        }
    }
    else {
        if (DBL_PTR(_5956)->dbl == 0.0) {
            goto LA;
        }
    }
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_result);
    _5961 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5961);
    _0 = _5961;
    _5961 = binary_op(NOTEQ, _5961, _4NOVALUE);
    DeRef(_0);
L26:
    if (_5961 == 0) {
        goto LA;
    }
    else {
        if (!IS_ATOM_INT(_5961) && DBL_PTR(_5961)->dbl == 0.0)
            goto LA;
    }

    // 		intres = result[MIN]
    DeRef(_intres);
    _2 = (int)SEQ_PTR(_result);
    _intres = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_intres);

    // 		c_stmt("@ = ", target)
    RefDS(_5789);
    _16c_stmt(_5789, _target);

    // 		c_printf("%d;\n", intres)
    RefDS(_5980);
    Ref(_intres);
    _9c_printf(_5980, _intres);
L27:
L28:
    goto LA;
L18:

    //     elsif op = POWER then
    if (_op != 72)
        goto L29;

    // 	if left_val[MIN] = left_val[MAX] and
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_left_val);
    _5961 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5961);
    DeRef(_5956);
    _2 = (int)SEQ_PTR(_left_val);
    _5956 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5956);
    _0 = _5956;
    if (IS_ATOM_INT(_5961) && IS_ATOM_INT(_5956)) {
        _5956 = (_5961 == _5956);
    }
    else {
        _5956 = binary_op(EQUALS, _5961, _5956);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_5956)) {
        if (_5956 == 0) {
            goto L2A;
        }
    }
    else {
        if (DBL_PTR(_5956)->dbl == 0.0) {
            goto L2A;
        }
    }
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_right_val);
    _5961 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5961);
    DeRef(_6057);
    _2 = (int)SEQ_PTR(_right_val);
    _6057 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6057);
    _0 = _6057;
    if (IS_ATOM_INT(_5961) && IS_ATOM_INT(_6057)) {
        _6057 = (_5961 == _6057);
    }
    else {
        _6057 = binary_op(EQUALS, _5961, _6057);
    }
    DeRef(_0);
L2B:
    if (_6057 == 0) {
        goto L2A;
    }
    else {
        if (!IS_ATOM_INT(_6057) && DBL_PTR(_6057)->dbl == 0.0)
            goto L2A;
    }

    // 	    p1 = power(left_val[MIN], right_val[MIN])
    DeRef(_6057);
    _2 = (int)SEQ_PTR(_left_val);
    _6057 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6057);
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_right_val);
    _5961 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5961);
    DeRef(_p1);
    if (IS_ATOM_INT(_6057) && IS_ATOM_INT(_5961)) {
        _p1 = power(_6057, _5961);
    }
    else {
        _p1 = binary_op(POWER, _6057, _5961);
    }

    // 	    if integer(p1) then
    DeRef(_5961);
    if (IS_ATOM_INT(_p1))
        _5961 = 1;
    else if (IS_ATOM_DBL(_p1))
        _5961 = IS_ATOM_INT(DoubleToInt(_p1));
    else
        _5961 = 0;
    if (_5961 == 0)
        goto LA;

    // 		result[MIN] = p1
    Ref(_p1);
    _2 = (int)SEQ_PTR(_result);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _result = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _p1;
    DeRef(_1);

    // 		result[MAX] = result[MIN]
    _2 = (int)SEQ_PTR(_result);
    _5961 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5961);
    Ref(_5961);
    _2 = (int)SEQ_PTR(_result);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _result = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _5961;
    DeRef(_1);

    // 		c_stmt("@ = ", target)
    RefDS(_5789);
    _16c_stmt(_5789, _target);

    // 		c_printf("%d;\n", result[MIN])
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_result);
    _5961 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5961);
    RefDS(_5980);
    Ref(_5961);
    _9c_printf(_5980, _5961);
L2C:
    goto LA;
L2A:

    // 	    if right_val[MAX] <= 4 and right_val[MIN] >= 0 and
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_right_val);
    _5961 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5961);
    _0 = _5961;
    if (IS_ATOM_INT(_5961)) {
        _5961 = (_5961 <= 4);
    }
    else {
        _5961 = binary_op(LESSEQ, _5961, 4);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_5961)) {
        if (_5961 == 0) {
            DeRef(_5961);
            _5961 = 0;
            goto L2D;
        }
    }
    else {
        if (DBL_PTR(_5961)->dbl == 0.0) {
            DeRef(_5961);
            _5961 = 0;
            goto L2D;
        }
    }
    DeRef(_6057);
    _2 = (int)SEQ_PTR(_right_val);
    _6057 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6057);
    _0 = _6057;
    if (IS_ATOM_INT(_6057)) {
        _6057 = (_6057 >= 0);
    }
    else {
        _6057 = binary_op(GREATEREQ, _6057, 0);
    }
    DeRef(_0);
    DeRef(_5961);
    if (IS_ATOM_INT(_6057))
        _5961 = (_6057 != 0);
    else
        _5961 = DBL_PTR(_6057)->dbl != 0.0;
L2D:
    if (_5961 == 0) {
        DeRef(_6057);
        _6057 = 0;
        goto L2E;
    }
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_left_val);
    _5961 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5961);
    _0 = _5961;
    if (IS_ATOM_INT(_5961)) {
        _5961 = (_5961 < 177);
    }
    else {
        _5961 = binary_op(LESS, _5961, 177);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_5961))
        _6057 = (_5961 != 0);
    else
        _6057 = DBL_PTR(_5961)->dbl != 0.0;
L2E:
    if (_6057 == 0) {
        goto LA;
    }
    DeRef(_6057);
    _2 = (int)SEQ_PTR(_left_val);
    _6057 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6057);
    _0 = _6057;
    if (IS_ATOM_INT(_6057)) {
        _6057 = (_6057 > -177);
    }
    else {
        _6057 = binary_op(GREATER, _6057, -177);
    }
    DeRef(_0);
L2F:
    if (_6057 == 0) {
        goto LA;
    }
    else {
        if (!IS_ATOM_INT(_6057) && DBL_PTR(_6057)->dbl == 0.0)
            goto LA;
    }

    // 		result[MIN] = MININT
    _2 = (int)SEQ_PTR(_result);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _result = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = -1073741824;
    DeRef(_1);

    // 		result[MAX] = MAXINT
    _2 = (int)SEQ_PTR(_result);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _result = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = 1073741823;
    DeRef(_1);
L30:
L31:
    goto LA;
L29:

    // 	if left_val[MIN] = left_val[MAX] and
    DeRef(_6057);
    _2 = (int)SEQ_PTR(_left_val);
    _6057 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6057);
    DeRef(_5961);
    _2 = (int)SEQ_PTR(_left_val);
    _5961 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5961);
    _0 = _5961;
    if (IS_ATOM_INT(_6057) && IS_ATOM_INT(_5961)) {
        _5961 = (_6057 == _5961);
    }
    else {
        _5961 = binary_op(EQUALS, _6057, _5961);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_5961)) {
        if (_5961 == 0) {
            DeRef(_5961);
            _5961 = 0;
            goto L32;
        }
    }
    else {
        if (DBL_PTR(_5961)->dbl == 0.0) {
            DeRef(_5961);
            _5961 = 0;
            goto L32;
        }
    }
    DeRef(_6057);
    _2 = (int)SEQ_PTR(_right_val);
    _6057 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6057);
    DeRef(_5956);
    _2 = (int)SEQ_PTR(_right_val);
    _5956 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5956);
    _0 = _5956;
    if (IS_ATOM_INT(_6057) && IS_ATOM_INT(_5956)) {
        _5956 = (_6057 == _5956);
    }
    else {
        _5956 = binary_op(EQUALS, _6057, _5956);
    }
    DeRef(_0);
    DeRef(_5961);
    if (IS_ATOM_INT(_5956))
        _5961 = (_5956 != 0);
    else
        _5961 = DBL_PTR(_5956)->dbl != 0.0;
L32:
    if (_5961 == 0) {
        goto L33;
    }
    DeRef(_6057);
    _2 = (int)SEQ_PTR(_right_val);
    _6057 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6057);
    _0 = _6057;
    if (IS_ATOM_INT(_6057)) {
        _6057 = (_6057 != 0);
    }
    else {
        _6057 = binary_op(NOTEQ, _6057, 0);
    }
    DeRef(_0);
L34:
    if (_6057 == 0) {
        goto L33;
    }
    else {
        if (!IS_ATOM_INT(_6057) && DBL_PTR(_6057)->dbl == 0.0)
            goto L33;
    }

    // 		intres = floor(left_val[MIN] / right_val[MIN])
    DeRef(_6057);
    _2 = (int)SEQ_PTR(_left_val);
    _6057 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6057);
    DeRef(_5956);
    _2 = (int)SEQ_PTR(_right_val);
    _5956 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5956);
    DeRef(_intres);
    if (IS_ATOM_INT(_6057) && IS_ATOM_INT(_5956)) {
        if (_5956 > 0 && _6057 >= 0) {
            _intres = _6057 / _5956;
        }
        else {
            temp_dbl = floor((double)_6057 / (double)_5956);
            if (_6057 != MININT)
                _intres = (long)temp_dbl;
            else
                _intres = NewDouble(temp_dbl);
        }
    }
    else {
        _2 = binary_op(DIVIDE, _6057, _5956);
        _intres = unary_op(FLOOR, _2);
        DeRef(_2);
    }

    // 	    if intres >= MININT and intres <= MAXINT then
    DeRef(_5956);
    if (IS_ATOM_INT(_intres)) {
        _5956 = (_intres >= -1073741824);
    }
    else {
        _5956 = (DBL_PTR(_intres)->dbl >= (double)-1073741824);
    }
    if (_5956 == 0) {
        goto L35;
    }
    DeRef(_6057);
    if (IS_ATOM_INT(_intres)) {
        _6057 = (_intres <= 1073741823);
    }
    else {
        _6057 = (DBL_PTR(_intres)->dbl <= (double)1073741823);
    }
L36:
    if (_6057 == 0)
        goto L35;

    // 		c_stmt("@ = ", target)
    RefDS(_5789);
    _16c_stmt(_5789, _target);

    // 		c_printf("%d;\n", intres)
    RefDS(_5980);
    Ref(_intres);
    _9c_printf(_5980, _intres);

    // 		result[MIN] = intres
    Ref(_intres);
    _2 = (int)SEQ_PTR(_result);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _result = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _intres;
    DeRef(_1);

    // 		result[MAX] = result[MIN]
    DeRef(_6057);
    _2 = (int)SEQ_PTR(_result);
    _6057 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6057);
    Ref(_6057);
    _2 = (int)SEQ_PTR(_result);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _result = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _6057;
    DeRef(_1);
L37:
    goto L35;
L33:

    // 	    if right_val[MIN] >= 2 then
    DeRef(_6057);
    _2 = (int)SEQ_PTR(_right_val);
    _6057 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6057);
    if (binary_op_a(LESS, _6057, 2))
        goto L38;

    // 		result[MIN] = left_val[MIN] / right_val[MIN] - 1
    DeRef(_6057);
    _2 = (int)SEQ_PTR(_left_val);
    _6057 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6057);
    DeRef(_5956);
    _2 = (int)SEQ_PTR(_right_val);
    _5956 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5956);
    _0 = _5956;
    if (IS_ATOM_INT(_6057) && IS_ATOM_INT(_5956)) {
        _5956 = (_6057 % _5956) ? NewDouble((double)_6057 / _5956) : (_6057 / _5956);
    }
    else {
        _5956 = binary_op(DIVIDE, _6057, _5956);
    }
    DeRef(_0);
    _0 = _5956;
    if (IS_ATOM_INT(_5956)) {
        _5956 = _5956 - 1;
        if ((long)((unsigned long)_5956 +(unsigned long) HIGH_BITS) >= 0)
            _5956 = NewDouble((double)_5956);
    }
    else {
        _5956 = binary_op(MINUS, _5956, 1);
    }
    DeRef(_0);
    Ref(_5956);
    _2 = (int)SEQ_PTR(_result);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _result = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _5956;
    DeRef(_1);

    // 		result[MAX] = left_val[MAX] / right_val[MIN] + 1
    DeRef(_5956);
    _2 = (int)SEQ_PTR(_left_val);
    _5956 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5956);
    DeRef(_6057);
    _2 = (int)SEQ_PTR(_right_val);
    _6057 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6057);
    _0 = _6057;
    if (IS_ATOM_INT(_5956) && IS_ATOM_INT(_6057)) {
        _6057 = (_5956 % _6057) ? NewDouble((double)_5956 / _6057) : (_5956 / _6057);
    }
    else {
        _6057 = binary_op(DIVIDE, _5956, _6057);
    }
    DeRef(_0);
    _0 = _6057;
    if (IS_ATOM_INT(_6057)) {
        _6057 = _6057 + 1;
        if (_6057 > MAXINT)
            _6057 = NewDouble((double)_6057);
    }
    else
        _6057 = binary_op(PLUS, 1, _6057);
    DeRef(_0);
    Ref(_6057);
    _2 = (int)SEQ_PTR(_result);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _result = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _6057;
    DeRef(_1);
L38:
L35:
LA:

    //     return result
    DeRef(_left_val);
    DeRef(_right_val);
    DeRef(_intres);
    DeRef(_d1);
    DeRef(_d2);
    DeRef(_d3);
    DeRef(_d4);
    DeRef(_p1);
    DeRef(_p2);
    DeRef(_p3);
    DeRef(_p4);
    DeRef(_6057);
    DeRef(_5956);
    DeRef(_5961);
    return _result;
    ;
}


int _18FlushDeRef()
{
    int _6106;
    int _6104;
    int _0, _1, _2;
    

    //     for i = 1 to length(deref_buff) do 
    _6104 = SEQ_PTR(_18deref_buff)->length;
    { int _i;
        _i = 1;
L1:
        if (_i > _6104)
            goto L2;

        // 	LeftSym = TRUE
        _16LeftSym = 1;

        // 	c_stmt("DeRef(@);\n", deref_buff[i])
        _2 = (int)SEQ_PTR(_18deref_buff);
        _6106 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_6105);
        _16c_stmt(_6105, _6106);

        //     end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    //     deref_buff = {}
    RefDS(_39);
    DeRefi(_18deref_buff);
    _18deref_buff = _39;

    // end procedure
    return 0;
    ;
}


int _18FinalDeRef(int _sym)
{
    int _i;
    int _t;
    int _6111;
    int _6107;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_sym)) {
        _1 = (long)(DBL_PTR(_sym)->dbl);
        DeRefDS(_sym);
        _sym = _1;
    }

    //     i = BB_temp_type(sym)
    _i = _18BB_temp_type(_sym);

    //     t = BB_temp_elem(sym)
    _t = _18BB_temp_elem(_sym);

    //     if i != TYPE_INTEGER and i != TYPE_NULL then
    _6107 = (_i != 1);
    if (_6107 == 0) {
        goto L1;
    }
    _6111 = (_i != 0);
L2:
    if (_6111 == 0)
        goto L1;

    // 	LeftSym = TRUE
    _16LeftSym = 1;

    // 	if i = TYPE_ATOM then
    if (_i != 4)
        goto L3;

    // 	    deref_buff = append(deref_buff, sym)
    Append(&_18deref_buff, _18deref_buff, _sym);
    goto L4;
L3:

    // 	elsif i = TYPE_OBJECT then
    if (_i != 16)
        goto L5;

    // 	    if t = TYPE_INTEGER then
    if (_t != 1)
        goto L6;

    // 		c_stmt("DeRefi(@);\n", sym)
    RefDS(_6116);
    _16c_stmt(_6116, _sym);
    goto L4;
L6:

    // 		deref_buff = append(deref_buff, sym)
    Append(&_18deref_buff, _18deref_buff, _sym);
L7:
    goto L4;
L5:

    // 	elsif i = TYPE_SEQUENCE then
    if (_i != 8)
        goto L8;

    // 	    if t = TYPE_INTEGER then
    if (_t != 1)
        goto L9;

    // 		c_stmt("DeRefDSi(@);\n", sym)
    RefDS(_6120);
    _16c_stmt(_6120, _sym);
    goto L4;
L9:

    // 		c_stmt("DeRefDS(@);\n", sym)
    RefDS(_6121);
    _16c_stmt(_6121, _sym);
LA:
    goto L4;
L8:

    // 	    c_stmt("DeRefDS(@);\n", sym)
    RefDS(_6121);
    _16c_stmt(_6121, _sym);
L4:

    // 	if length(deref_buff) = DEREF_PACK then
    _6111 = SEQ_PTR(_18deref_buff)->length;
    if (_6111 != 5)
        goto LB;

    // 	    LeftSym = TRUE
    _16LeftSym = 1;

    // 	    c_stmt("DeRef5(@", deref_buff[1])
    _2 = (int)SEQ_PTR(_18deref_buff);
    _6111 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_6124);
    _16c_stmt(_6124, _6111);

    // 	    for d = 2 to DEREF_PACK do
    { int _d;
        _d = 2;
LC:
        if (_d > 5)
            goto LD;

        // 		c_puts(", ")
        RefDS(_5165);
        _9c_puts(_5165);

        // 		LeftSym = TRUE
        _16LeftSym = 1;

        // 		CName(deref_buff[d])
        _2 = (int)SEQ_PTR(_18deref_buff);
        _6111 = (int)*(((s1_ptr)_2)->base + _d);
        _16CName(_6111);

        // 	    end for 
        _d = _d + 1;
        goto LC;
LD:
        ;
    }

    // 	    c_puts(");\n") 
    RefDS(_4675);
    _9c_puts(_4675);

    // 	    deref_buff = {}
    RefDS(_39);
    DeRefi(_18deref_buff);
    _18deref_buff = _39;
LB:
L1:

    // end procedure
    return 0;
    ;
}


int _18NotInRange(int _x, int _badval)
{
    int _range = 0;
    int _6127 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_x)) {
        _1 = (long)(DBL_PTR(_x)->dbl);
        DeRefDS(_x);
        _x = _1;
    }
    if (!IS_ATOM_INT(_badval)) {
        _1 = (long)(DBL_PTR(_badval)->dbl);
        DeRefDS(_badval);
        _badval = _1;
    }

    //     range = ObjMinMax(x)
    _range = _18ObjMinMax(_x);

    //     if range[MIN] > badval then
    _2 = (int)SEQ_PTR(_range);
    _6127 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6127);
    if (binary_op_a(LESSEQ, _6127, _badval))
        goto L1;

    // 	return TRUE
    DeRefDS(_range);
    DeRef(_6127);
    return 1;
L1:

    //     if range[MAX] < badval then
    DeRef(_6127);
    _2 = (int)SEQ_PTR(_range);
    _6127 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6127);
    if (binary_op_a(GREATEREQ, _6127, _badval))
        goto L2;

    // 	return TRUE
    DeRefDS(_range);
    DeRef(_6127);
    return 1;
L2:

    //     return FALSE
    DeRef(_range);
    DeRef(_6127);
    return 0;
    ;
}


int _18IntegerMultiply(int _a, int _b)
{
    int _multiply_code = 0;
    int _dblcode = 0;
    int _test_a = 0;
    int _test_b1 = 0;
    int _test_b2 = 0;
    int _range_a = 0;
    int _range_b = 0;
    int _6143 = 0;
    int _6132 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_a)) {
        _1 = (long)(DBL_PTR(_a)->dbl);
        DeRefDS(_a);
        _a = _1;
    }
    if (!IS_ATOM_INT(_b)) {
        _1 = (long)(DBL_PTR(_b)->dbl);
        DeRefDS(_b);
        _b = _1;
    }

    //     if TypeIs(a, TYPE_INTEGER) then
    _6132 = _16TypeIs(_a, 1);
    if (_6132 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_6132) && DBL_PTR(_6132)->dbl == 0.0)
            goto L1;
    }

    // 	range_a = ObjMinMax(a)
    _range_a = _18ObjMinMax(_a);
    goto L2;
L1:

    // 	range_a = {MININT, MAXINT}
    DeRef(_range_a);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -1073741824;
    ((int *)_2)[2] = 1073741823;
    _range_a = MAKE_SEQ(_1);
L2:

    //     if TypeIs(b, TYPE_INTEGER) then
    _0 = _6132;
    _6132 = _16TypeIs(_b, 1);
    DeRef(_0);
    if (_6132 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_6132) && DBL_PTR(_6132)->dbl == 0.0)
            goto L3;
    }

    // 	range_b = ObjMinMax(b)
    _0 = _range_b;
    _range_b = _18ObjMinMax(_b);
    DeRef(_0);
    goto L4;
L3:

    // 	range_b = {MININT, MAXINT}
    DeRef(_range_b);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -1073741824;
    ((int *)_2)[2] = 1073741823;
    _range_b = MAKE_SEQ(_1);
L4:

    //     dblcode = "@1 = NewDouble(@2 * (double)@3);\n"
    RefDS(_6138);
    DeRefi(_dblcode);
    _dblcode = _6138;

    //     if range_a[MIN] >= -INT16 and range_a[MAX] <= INT16 then
    DeRef(_6132);
    _2 = (int)SEQ_PTR(_range_a);
    _6132 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6132);
    _0 = _6132;
    if (IS_ATOM_INT(_6132)) {
        _6132 = (_6132 >= -32767);
    }
    else {
        _6132 = binary_op(GREATEREQ, _6132, -32767);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_6132)) {
        if (_6132 == 0) {
            goto L5;
        }
    }
    else {
        if (DBL_PTR(_6132)->dbl == 0.0) {
            goto L5;
        }
    }
    DeRef(_6143);
    _2 = (int)SEQ_PTR(_range_a);
    _6143 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6143);
    _0 = _6143;
    if (IS_ATOM_INT(_6143)) {
        _6143 = (_6143 <= 32767);
    }
    else {
        _6143 = binary_op(LESSEQ, _6143, 32767);
    }
    DeRef(_0);
L6:
    if (_6143 == 0) {
        goto L5;
    }
    else {
        if (!IS_ATOM_INT(_6143) && DBL_PTR(_6143)->dbl == 0.0)
            goto L5;
    }

    // 	test_a = ""     -- will pass for sure
    RefDS(_39);
    DeRefi(_test_a);
    _test_a = _39;
    goto L7;
L5:

    //     elsif range_a[MAX] < -INT16 or range_a[MIN] > INT16 then    
    DeRef(_6143);
    _2 = (int)SEQ_PTR(_range_a);
    _6143 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6143);
    _0 = _6143;
    if (IS_ATOM_INT(_6143)) {
        _6143 = (_6143 < -32767);
    }
    else {
        _6143 = binary_op(LESS, _6143, -32767);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_6143)) {
        if (_6143 != 0) {
            goto L8;
        }
    }
    else {
        if (DBL_PTR(_6143)->dbl != 0.0) {
            goto L8;
        }
    }
    DeRef(_6132);
    _2 = (int)SEQ_PTR(_range_a);
    _6132 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6132);
    _0 = _6132;
    if (IS_ATOM_INT(_6132)) {
        _6132 = (_6132 > 32767);
    }
    else {
        _6132 = binary_op(GREATER, _6132, 32767);
    }
    DeRef(_0);
L9:
    if (_6132 == 0) {
        goto LA;
    }
    else {
        if (!IS_ATOM_INT(_6132) && DBL_PTR(_6132)->dbl == 0.0)
            goto LA;
    }
L8:

    // 	return dblcode  -- will fail for sure
    DeRefi(_multiply_code);
    DeRefi(_test_a);
    DeRefi(_test_b1);
    DeRefi(_test_b2);
    DeRef(_range_a);
    DeRef(_range_b);
    DeRef(_6143);
    DeRef(_6132);
    return _dblcode;
    goto L7;
LA:

    // 	test_a = "@2 == (short)@2"  -- not sure
    RefDS(_6150);
    DeRefi(_test_a);
    _test_a = _6150;
L7:

    //     if range_b[MAX] <= INT15 then
    DeRef(_6132);
    _2 = (int)SEQ_PTR(_range_b);
    _6132 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6132);
    if (binary_op_a(GREATER, _6132, 16383))
        goto LB;

    // 	test_b1 = ""    -- will pass for sure
    RefDS(_39);
    DeRefi(_test_b1);
    _test_b1 = _39;
    goto LC;
LB:

    //     elsif range_b[MIN] > INT15 then
    DeRef(_6132);
    _2 = (int)SEQ_PTR(_range_b);
    _6132 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6132);
    if (binary_op_a(LESSEQ, _6132, 16383))
        goto LD;

    // 	return dblcode  -- will fail for sure
    DeRefi(_multiply_code);
    DeRefi(_test_a);
    DeRefi(_test_b1);
    DeRefi(_test_b2);
    DeRef(_range_a);
    DeRefDS(_range_b);
    DeRef(_6143);
    DeRef(_6132);
    return _dblcode;
    goto LC;
LD:

    // 	test_b1 = "@3 <= INT15"  -- not sure
    RefDS(_6155);
    DeRefi(_test_b1);
    _test_b1 = _6155;
LC:

    //     if range_b[MIN] >= -INT15 then
    DeRef(_6132);
    _2 = (int)SEQ_PTR(_range_b);
    _6132 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6132);
    if (binary_op_a(LESS, _6132, -16383))
        goto LE;

    // 	test_b2 = ""    -- will pass for sure
    RefDS(_39);
    DeRefi(_test_b2);
    _test_b2 = _39;
    goto LF;
LE:

    //     elsif range_b[MAX] < -INT15 then
    DeRef(_6132);
    _2 = (int)SEQ_PTR(_range_b);
    _6132 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6132);
    if (binary_op_a(GREATEREQ, _6132, -16383))
        goto L10;

    // 	return dblcode  -- will fail for sure
    DeRefi(_multiply_code);
    DeRefi(_test_a);
    DeRefi(_test_b1);
    DeRefi(_test_b2);
    DeRef(_range_a);
    DeRefDS(_range_b);
    DeRef(_6143);
    DeRef(_6132);
    return _dblcode;
    goto LF;
L10:

    // 	test_b2 = "@3 >= -INT15"  -- not sure
    RefDS(_6161);
    DeRefi(_test_b2);
    _test_b2 = _6161;
LF:

    //     multiply_code = "if ("
    RefDS(_6162);
    DeRefi(_multiply_code);
    _multiply_code = _6162;

    //     multiply_code &= test_a
    Concat((object_ptr)&_multiply_code, _multiply_code, (s1_ptr)_test_a);

    //     if length(test_a) and length(test_b1) then 
    DeRef(_6132);
    _6132 = SEQ_PTR(_test_a)->length;
    if (_6132 == 0) {
        goto L11;
    }
    DeRef(_6143);
    _6143 = SEQ_PTR(_test_b1)->length;
L12:
    if (_6143 == 0)
        goto L11;

    // 	multiply_code &= " && "
    Concat((object_ptr)&_multiply_code, _multiply_code, (s1_ptr)_6167);
L11:

    //     multiply_code &= test_b1
    Concat((object_ptr)&_multiply_code, _multiply_code, (s1_ptr)_test_b1);

    //     if (length(test_a) or length(test_b1)) and length(test_b2) then 
    DeRef(_6143);
    _6143 = SEQ_PTR(_test_a)->length;
    if (_6143 != 0) {
        _6143 = 1;
        goto L13;
    }
    DeRef(_6132);
    _6132 = SEQ_PTR(_test_b1)->length;
    _6143 = (_6132 != 0);
L13:
    if (_6143 == 0) {
        goto L14;
    }
    DeRef(_6143);
    _6143 = SEQ_PTR(_test_b2)->length;
L15:
    if (_6143 == 0)
        goto L14;

    // 	multiply_code &= " && " 
    Concat((object_ptr)&_multiply_code, _multiply_code, (s1_ptr)_6167);
L14:

    //     multiply_code &= test_b2
    Concat((object_ptr)&_multiply_code, _multiply_code, (s1_ptr)_test_b2);

    //     if length(test_a) or length(test_b1) or length(test_b2) then
    DeRef(_6143);
    _6143 = SEQ_PTR(_test_a)->length;
    if (_6143 != 0) {
        _6143 = 1;
        goto L16;
    }
    DeRef(_6132);
    _6132 = SEQ_PTR(_test_b1)->length;
    _6143 = (_6132 != 0);
L16:
    if (_6143 != 0) {
        goto L17;
    }
    DeRef(_6143);
    _6143 = SEQ_PTR(_test_b2)->length;
L18:
    if (_6143 == 0)
        goto L19;
L17:

    // 	multiply_code &= ")\n" &
    {
        int concat_list[4];

        concat_list[0] = _6138;
        concat_list[1] = _5799;
        concat_list[2] = _6182;
        concat_list[3] = _5168;
        Concat_N((object_ptr)&_6143, concat_list, 4);
    }
    Concat((object_ptr)&_multiply_code, _multiply_code, (s1_ptr)_6143);
    goto L1A;
L19:

    // 	multiply_code = "@1 = @2 * @3;\n"  -- no tests, must be integer
    RefDS(_6182);
    DeRefi(_multiply_code);
    _multiply_code = _6182;
L1A:

    //     return multiply_code
    DeRefi(_dblcode);
    DeRefi(_test_a);
    DeRefi(_test_b1);
    DeRefi(_test_b2);
    DeRef(_range_a);
    DeRef(_range_b);
    DeRef(_6143);
    DeRef(_6132);
    return _multiply_code;
    ;
}


