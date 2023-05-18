// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

main0()
{
    int _741 = 0;
    int _743 = 0;
    int _745 = 0;
    int _747 = 0;
    int _749 = 0;
    int _751 = 0;
    int _753 = 0;
    int _755 = 0;
    int _757 = 0;
    int _759 = 0;
    int _761 = 0;
    int _763 = 0;
    int _765 = 0;
    int _767 = 0;
    int _769 = 0;
    int _771 = 0;
    int _773 = 0;
    int _775 = 0;
    int _777 = 0;
    int _779 = 0;
    int _781 = 0;
    int _783 = 0;
    int _785 = 0;
    int _787 = 0;
    int _789 = 0;
    int _791 = 0;
    int _793 = 0;
    int _795 = 0;
    int _797 = 0;
    int _799 = 0;
    int _801 = 0;
    int _803 = 0;
    int _805 = 0;
    int _807 = 0;
    int _809 = 0;
    int _811 = 0;
    int _813 = 0;
    int _815 = 0;
    int _817 = 0;
    int _819 = 0;
    int _821 = 0;
    int _823 = 0;
    int _825 = 0;
    int _827 = 0;
    int _829 = 0;
    int _831 = 0;
    int _833 = 0;
    int _835 = 0;
    int _837 = 0;
    int _839 = 0;
    int _841 = 0;
    int _843 = 0;
    int _845 = 0;
    int _847 = 0;
    int _849 = 0;
    int _851 = 0;
    int _853 = 0;
    int _855 = 0;
    int _857 = 0;
    int _739 = 0;
    int _737 = 0;
    int _735 = 0;
    int _733 = 0;
    int _731 = 0;
    int _729 = 0;
    int _727 = 0;
    int _725 = 0;
    int _723 = 0;
    int _721 = 0;
    int _719 = 0;
    int _717 = 0;
    int _715 = 0;
    int _713 = 0;
    int _711 = 0;
    int _709 = 0;
    int _707 = 0;
    int _705 = 0;
    int _703 = 0;
    int _701 = 0;
    int _699 = 0;
    int _697 = 0;
    int _695 = 0;
    int _693 = 0;
    int _691 = 0;
    int _689 = 0;
    int _687 = 0;
    int _685 = 0;
    int _683 = 0;
    int _681 = 0;
    int _679 = 0;
    int _677 = 0;
    int _675 = 0;
    int _673 = 0;
    int _671 = 0;
    int _669 = 0;
    int _667 = 0;
    int _665 = 0;
    int _663 = 0;
    int _152 = 0;
    int _0, _1, _2;
    
    

    // op_result = repeat(T_UNKNOWN, MAX_OPCODE)
    DeRef1(_14op_result);
    _14op_result = Repeat(5, 179);

    // op_result[RIGHT_BRACE_N] = T_SEQUENCE
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 31);
    *(int *)_2 = 3;

    // op_result[RIGHT_BRACE_2] = T_SEQUENCE
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 85);
    *(int *)_2 = 3;

    // op_result[REPEAT] = T_SEQUENCE
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 32);
    *(int *)_2 = 3;

    // op_result[APPEND] = T_SEQUENCE
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 35);
    *(int *)_2 = 3;

    // op_result[RHS_SLICE] = T_SEQUENCE
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 46);
    *(int *)_2 = 3;

    // op_result[CONCAT] = T_SEQUENCE
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 15);
    *(int *)_2 = 3;

    // op_result[CONCAT_N] = T_SEQUENCE
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 159);
    *(int *)_2 = 3;

    // op_result[PREPEND] = T_SEQUENCE
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 57);
    *(int *)_2 = 3;

    // op_result[COMMAND_LINE] = T_SEQUENCE
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 100);
    *(int *)_2 = 3;

    // op_result[SPRINTF] = T_SEQUENCE
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 53);
    *(int *)_2 = 3;

    // op_result[ROUTINE_ID] = T_INTEGER
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 136);
    *(int *)_2 = 1;

    // op_result[GETC] = T_INTEGER
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 33);
    *(int *)_2 = 1;

    // op_result[OPEN] = T_INTEGER
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 37);
    *(int *)_2 = 1;

    // op_result[LENGTH] = T_INTEGER   -- assume less than a billion
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 42);
    *(int *)_2 = 1;

    // op_result[PLENGTH] = T_INTEGER  -- ""
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 162);
    *(int *)_2 = 1;

    // op_result[IS_AN_OBJECT] = T_INTEGER
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 40);
    *(int *)_2 = 1;

    // op_result[IS_AN_ATOM] = T_INTEGER
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 67);
    *(int *)_2 = 1;

    // op_result[IS_A_SEQUENCE] = T_INTEGER
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 68);
    *(int *)_2 = 1;

    // op_result[COMPARE] = T_INTEGER
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 76);
    *(int *)_2 = 1;

    // op_result[EQUAL] = T_INTEGER
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 155);
    *(int *)_2 = 1;

    // op_result[FIND] = T_INTEGER
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 77);
    *(int *)_2 = 1;

    // op_result[FIND_FROM] = T_INTEGER
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 178);
    *(int *)_2 = 1;

    // op_result[MATCH]  = T_INTEGER
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 78);
    *(int *)_2 = 1;

    // op_result[MATCH_FROM]  = T_INTEGER
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 179);
    *(int *)_2 = 1;

    // op_result[GET_KEY] = T_INTEGER
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 79);
    *(int *)_2 = 1;

    // op_result[IS_AN_INTEGER] = T_INTEGER
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 94);
    *(int *)_2 = 1;

    // op_result[ASSIGN_I] = T_INTEGER
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 113);
    *(int *)_2 = 1;

    // op_result[RHS_SUBS_I] = T_INTEGER
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 114);
    *(int *)_2 = 1;

    // op_result[PLUS_I] = T_INTEGER
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 115);
    *(int *)_2 = 1;

    // op_result[MINUS_I] = T_INTEGER
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 116);
    *(int *)_2 = 1;

    // op_result[PLUS1_I] = T_INTEGER
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 117);
    *(int *)_2 = 1;

    // op_result[SYSTEM_EXEC] = T_INTEGER
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 156);
    *(int *)_2 = 1;

    // op_result[TIME] = T_ATOM
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 70);
    *(int *)_2 = 4;

    // op_result[TASK_STATUS] = T_INTEGER
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 175);
    *(int *)_2 = 1;

    // op_result[TASK_SELF] = T_ATOM
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 172);
    *(int *)_2 = 4;

    // op_result[TASK_CREATE] = T_ATOM
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 169);
    *(int *)_2 = 4;

    // op_result[TASK_LIST] = T_SEQUENCE
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 174);
    *(int *)_2 = 3;

    // op_result[PLATFORM] = T_INTEGER
    _2 = (int)SEQ_PTR(_14op_result);
    _2 = (int)(((s1_ptr)_2)->base + 157);
    *(int *)_2 = 1;

    // sample_size = 0
    _15sample_size = 0;

    // max_stack_per_call = 1
    _15max_stack_per_call = 1;

    // branch_list = {}
    RefDS(_39);
    DeRef1(_15branch_list);
    _15branch_list = _39;

    // short_circuit = 0
    _15short_circuit = 0;

    // short_circuit_B = FALSE   -- circuit expression? given short_circuit is TRUE.
    _15short_circuit_B = 0;

    // side_effect_calls = 0     -- on local/global variables
    _15side_effect_calls = 0;

    // factors = 0
    _15factors = 0;

    // lhs_subs_level = -1
    _15lhs_subs_level = -1;

    // left_sym = 0
    _15left_sym = 0;

    // forward_expr = routine_id("Expr")
    _15forward_expr = CRoutineId(181, 15, _3313);

    // forward_Statement_list = routine_id("Statement_list")
    _15forward_Statement_list = CRoutineId(195, 15, _3698);

    // mix_msg = "can't mix profile and profile_time"
    RefDS(_3842);
    DeRef1(_15mix_msg);
    _15mix_msg = _3842;

    // BB_info = {}
    RefDS(_39);
    DeRef1(_16BB_info);
    _16BB_info = _39;

    // LeftSym = FALSE    
    _16LeftSym = 0;

    // dll_option = FALSE
    _16dll_option = 0;

    // con_option = FALSE
    _16con_option = 0;

    // fastfp = FALSE
    _16fastfp = 0;

    // files_to_delete = {
    _0 = _16files_to_delete;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_3942);
    *((int *)(_2+4)) = _3942;
    RefDS(_3943);
    *((int *)(_2+8)) = _3943;
    RefDS(_3944);
    *((int *)(_2+12)) = _3944;
    _16files_to_delete = MAKE_SEQ(_1);
    DeRef1(_0);

    // keep = FALSE
    _16keep = 0;

    // total_stack_size = -1  -- (for now) 
    _16total_stack_size = -1;

    // deleted_routines = 0
    _16deleted_routines = 0;
    RefDS(_4831);
    _16file_chars = _4831;
    _1 = NewS1(179);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_5252);
    *((int *)(_2+4)) = _5252;
    RefDS(_5253);
    *((int *)(_2+8)) = _5253;
    RefDS(_5254);
    *((int *)(_2+12)) = _5254;
    RefDS(_5255);
    *((int *)(_2+16)) = _5255;
    RefDS(_5256);
    *((int *)(_2+20)) = _5256;
    RefDS(_5257);
    *((int *)(_2+24)) = _5257;
    RefDS(_5258);
    *((int *)(_2+28)) = _5258;
    RefDS(_5259);
    *((int *)(_2+32)) = _5259;
    RefDS(_5260);
    *((int *)(_2+36)) = _5260;
    RefDS(_5261);
    *((int *)(_2+40)) = _5261;
    RefDS(_5262);
    *((int *)(_2+44)) = _5262;
    RefDS(_5263);
    *((int *)(_2+48)) = _5263;
    RefDS(_5264);
    *((int *)(_2+52)) = _5264;
    RefDS(_5265);
    *((int *)(_2+56)) = _5265;
    RefDS(_5266);
    *((int *)(_2+60)) = _5266;
    RefDS(_5267);
    *((int *)(_2+64)) = _5267;
    RefDS(_5268);
    *((int *)(_2+68)) = _5268;
    RefDS(_5269);
    *((int *)(_2+72)) = _5269;
    RefDS(_5270);
    *((int *)(_2+76)) = _5270;
    RefDS(_5271);
    *((int *)(_2+80)) = _5271;
    RefDS(_5272);
    *((int *)(_2+84)) = _5272;
    RefDS(_5273);
    *((int *)(_2+88)) = _5273;
    RefDS(_5274);
    *((int *)(_2+92)) = _5274;
    RefDS(_5275);
    *((int *)(_2+96)) = _5275;
    RefDS(_5276);
    *((int *)(_2+100)) = _5276;
    RefDS(_5277);
    *((int *)(_2+104)) = _5277;
    RefDS(_5278);
    *((int *)(_2+108)) = _5278;
    RefDS(_5279);
    *((int *)(_2+112)) = _5279;
    RefDS(_5280);
    *((int *)(_2+116)) = _5280;
    RefDS(_5281);
    *((int *)(_2+120)) = _5281;
    RefDS(_5282);
    *((int *)(_2+124)) = _5282;
    RefDS(_5283);
    *((int *)(_2+128)) = _5283;
    RefDS(_5284);
    *((int *)(_2+132)) = _5284;
    RefDS(_5285);
    *((int *)(_2+136)) = _5285;
    RefDS(_5286);
    *((int *)(_2+140)) = _5286;
    RefDS(_5287);
    *((int *)(_2+144)) = _5287;
    RefDS(_5288);
    *((int *)(_2+148)) = _5288;
    RefDS(_5289);
    *((int *)(_2+152)) = _5289;
    RefDS(_5290);
    *((int *)(_2+156)) = _5290;
    RefDS(_5291);
    *((int *)(_2+160)) = _5291;
    RefDS(_5292);
    *((int *)(_2+164)) = _5292;
    RefDS(_5293);
    *((int *)(_2+168)) = _5293;
    RefDS(_5294);
    *((int *)(_2+172)) = _5294;
    RefDS(_5295);
    *((int *)(_2+176)) = _5295;
    RefDS(_5296);
    *((int *)(_2+180)) = _5296;
    RefDS(_5297);
    *((int *)(_2+184)) = _5297;
    RefDS(_5298);
    *((int *)(_2+188)) = _5298;
    RefDS(_5299);
    *((int *)(_2+192)) = _5299;
    RefDS(_5300);
    *((int *)(_2+196)) = _5300;
    RefDS(_5301);
    *((int *)(_2+200)) = _5301;
    RefDS(_5302);
    *((int *)(_2+204)) = _5302;
    RefDS(_5303);
    *((int *)(_2+208)) = _5303;
    RefDS(_5304);
    *((int *)(_2+212)) = _5304;
    RefDS(_5305);
    *((int *)(_2+216)) = _5305;
    RefDS(_5306);
    *((int *)(_2+220)) = _5306;
    RefDS(_5307);
    *((int *)(_2+224)) = _5307;
    RefDS(_5308);
    *((int *)(_2+228)) = _5308;
    RefDS(_5309);
    *((int *)(_2+232)) = _5309;
    RefDS(_5310);
    *((int *)(_2+236)) = _5310;
    RefDS(_5311);
    *((int *)(_2+240)) = _5311;
    RefDS(_5312);
    *((int *)(_2+244)) = _5312;
    RefDS(_5313);
    *((int *)(_2+248)) = _5313;
    RefDS(_5314);
    *((int *)(_2+252)) = _5314;
    RefDS(_5315);
    *((int *)(_2+256)) = _5315;
    RefDS(_5316);
    *((int *)(_2+260)) = _5316;
    RefDS(_5317);
    *((int *)(_2+264)) = _5317;
    RefDS(_5318);
    *((int *)(_2+268)) = _5318;
    RefDS(_5319);
    *((int *)(_2+272)) = _5319;
    RefDS(_5320);
    *((int *)(_2+276)) = _5320;
    RefDS(_5321);
    *((int *)(_2+280)) = _5321;
    RefDS(_5322);
    *((int *)(_2+284)) = _5322;
    RefDS(_5323);
    *((int *)(_2+288)) = _5323;
    RefDS(_5324);
    *((int *)(_2+292)) = _5324;
    RefDS(_5325);
    *((int *)(_2+296)) = _5325;
    RefDS(_5326);
    *((int *)(_2+300)) = _5326;
    RefDS(_5327);
    *((int *)(_2+304)) = _5327;
    RefDS(_5328);
    *((int *)(_2+308)) = _5328;
    RefDS(_5329);
    *((int *)(_2+312)) = _5329;
    RefDS(_5330);
    *((int *)(_2+316)) = _5330;
    RefDS(_5331);
    *((int *)(_2+320)) = _5331;
    RefDS(_5332);
    *((int *)(_2+324)) = _5332;
    RefDS(_5333);
    *((int *)(_2+328)) = _5333;
    RefDS(_5334);
    *((int *)(_2+332)) = _5334;
    RefDS(_5335);
    *((int *)(_2+336)) = _5335;
    RefDS(_5336);
    *((int *)(_2+340)) = _5336;
    RefDS(_5337);
    *((int *)(_2+344)) = _5337;
    RefDS(_5338);
    *((int *)(_2+348)) = _5338;
    RefDS(_5339);
    *((int *)(_2+352)) = _5339;
    RefDS(_5340);
    *((int *)(_2+356)) = _5340;
    RefDS(_5341);
    *((int *)(_2+360)) = _5341;
    RefDS(_5342);
    *((int *)(_2+364)) = _5342;
    RefDS(_5343);
    *((int *)(_2+368)) = _5343;
    RefDS(_5344);
    *((int *)(_2+372)) = _5344;
    RefDS(_5345);
    *((int *)(_2+376)) = _5345;
    RefDS(_5346);
    *((int *)(_2+380)) = _5346;
    RefDS(_5347);
    *((int *)(_2+384)) = _5347;
    RefDS(_5348);
    *((int *)(_2+388)) = _5348;
    RefDS(_5349);
    *((int *)(_2+392)) = _5349;
    RefDS(_5350);
    *((int *)(_2+396)) = _5350;
    RefDS(_5351);
    *((int *)(_2+400)) = _5351;
    RefDS(_5352);
    *((int *)(_2+404)) = _5352;
    RefDS(_5353);
    *((int *)(_2+408)) = _5353;
    RefDS(_5354);
    *((int *)(_2+412)) = _5354;
    RefDS(_5355);
    *((int *)(_2+416)) = _5355;
    RefDS(_5356);
    *((int *)(_2+420)) = _5356;
    RefDS(_5357);
    *((int *)(_2+424)) = _5357;
    RefDS(_5358);
    *((int *)(_2+428)) = _5358;
    RefDS(_5359);
    *((int *)(_2+432)) = _5359;
    RefDS(_5360);
    *((int *)(_2+436)) = _5360;
    RefDS(_5361);
    *((int *)(_2+440)) = _5361;
    RefDS(_5362);
    *((int *)(_2+444)) = _5362;
    RefDS(_5363);
    *((int *)(_2+448)) = _5363;
    RefDS(_5364);
    *((int *)(_2+452)) = _5364;
    RefDS(_5365);
    *((int *)(_2+456)) = _5365;
    RefDS(_5366);
    *((int *)(_2+460)) = _5366;
    RefDS(_5367);
    *((int *)(_2+464)) = _5367;
    RefDS(_5368);
    *((int *)(_2+468)) = _5368;
    RefDS(_5369);
    *((int *)(_2+472)) = _5369;
    RefDS(_5370);
    *((int *)(_2+476)) = _5370;
    RefDS(_5371);
    *((int *)(_2+480)) = _5371;
    RefDS(_5372);
    *((int *)(_2+484)) = _5372;
    RefDS(_5373);
    *((int *)(_2+488)) = _5373;
    RefDS(_5374);
    *((int *)(_2+492)) = _5374;
    RefDS(_5375);
    *((int *)(_2+496)) = _5375;
    RefDS(_5376);
    *((int *)(_2+500)) = _5376;
    RefDS(_5377);
    *((int *)(_2+504)) = _5377;
    RefDS(_5378);
    *((int *)(_2+508)) = _5378;
    RefDS(_5379);
    *((int *)(_2+512)) = _5379;
    RefDS(_5380);
    *((int *)(_2+516)) = _5380;
    RefDS(_5381);
    *((int *)(_2+520)) = _5381;
    RefDS(_5382);
    *((int *)(_2+524)) = _5382;
    RefDS(_5383);
    *((int *)(_2+528)) = _5383;
    RefDS(_5384);
    *((int *)(_2+532)) = _5384;
    RefDS(_5385);
    *((int *)(_2+536)) = _5385;
    RefDS(_5386);
    *((int *)(_2+540)) = _5386;
    RefDS(_5387);
    *((int *)(_2+544)) = _5387;
    RefDS(_5388);
    *((int *)(_2+548)) = _5388;
    RefDS(_5389);
    *((int *)(_2+552)) = _5389;
    RefDS(_5390);
    *((int *)(_2+556)) = _5390;
    RefDS(_5391);
    *((int *)(_2+560)) = _5391;
    RefDS(_5392);
    *((int *)(_2+564)) = _5392;
    RefDS(_5393);
    *((int *)(_2+568)) = _5393;
    RefDS(_5394);
    *((int *)(_2+572)) = _5394;
    RefDS(_5395);
    *((int *)(_2+576)) = _5395;
    RefDS(_5396);
    *((int *)(_2+580)) = _5396;
    RefDS(_5397);
    *((int *)(_2+584)) = _5397;
    RefDS(_5398);
    *((int *)(_2+588)) = _5398;
    RefDS(_5399);
    *((int *)(_2+592)) = _5399;
    RefDS(_5400);
    *((int *)(_2+596)) = _5400;
    RefDS(_5401);
    *((int *)(_2+600)) = _5401;
    RefDS(_5402);
    *((int *)(_2+604)) = _5402;
    RefDS(_5403);
    *((int *)(_2+608)) = _5403;
    RefDS(_5404);
    *((int *)(_2+612)) = _5404;
    RefDS(_5405);
    *((int *)(_2+616)) = _5405;
    RefDS(_5406);
    *((int *)(_2+620)) = _5406;
    RefDS(_5407);
    *((int *)(_2+624)) = _5407;
    RefDS(_5408);
    *((int *)(_2+628)) = _5408;
    RefDS(_5409);
    *((int *)(_2+632)) = _5409;
    RefDS(_5410);
    *((int *)(_2+636)) = _5410;
    RefDS(_5411);
    *((int *)(_2+640)) = _5411;
    RefDS(_5412);
    *((int *)(_2+644)) = _5412;
    RefDS(_5413);
    *((int *)(_2+648)) = _5413;
    RefDS(_5414);
    *((int *)(_2+652)) = _5414;
    RefDS(_5415);
    *((int *)(_2+656)) = _5415;
    RefDS(_5416);
    *((int *)(_2+660)) = _5416;
    RefDS(_5417);
    *((int *)(_2+664)) = _5417;
    RefDS(_5418);
    *((int *)(_2+668)) = _5418;
    RefDS(_5419);
    *((int *)(_2+672)) = _5419;
    RefDS(_5420);
    *((int *)(_2+676)) = _5420;
    RefDS(_5421);
    *((int *)(_2+680)) = _5421;
    RefDS(_5422);
    *((int *)(_2+684)) = _5422;
    RefDS(_5423);
    *((int *)(_2+688)) = _5423;
    RefDS(_5424);
    *((int *)(_2+692)) = _5424;
    RefDS(_5425);
    *((int *)(_2+696)) = _5425;
    RefDS(_5426);
    *((int *)(_2+700)) = _5426;
    RefDS(_5427);
    *((int *)(_2+704)) = _5427;
    RefDS(_5428);
    *((int *)(_2+708)) = _5428;
    RefDS(_5429);
    *((int *)(_2+712)) = _5429;
    RefDS(_5430);
    *((int *)(_2+716)) = _5430;
    _17opnames = MAKE_SEQ(_1);
    _18MAXLEN = 1072741823;

    // target = {0, 0}
    DeRef1(_18target);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 0;
    _18target = MAKE_SEQ(_1);

    // label_map = {}
    RefDS(_39);
    DeRef1(_18label_map);
    _18label_map = _39;

    // deref_buff = {}
    RefDS(_39);
    DeRef1(_18deref_buff);
    _18deref_buff = _39;

    // previous_previous_op = 0
    _18previous_previous_op = 0;

    // previous_op = 0
    _18previous_op = 0;

    // opcode = 0
    _18opcode = 0;

    // tasks_created = FALSE
    _18tasks_created = 0;

    // Execute_id = routine_id("Execute")
    _4Execute_id = CRoutineId(411, 18, _10397);
    RefDS(_10399);
    _18hex_chars = _10399;
    RefDS(_10588);
    _20DIGITS = _10588;
    Concat((object_ptr)&_20HEX_DIGITS, _20DIGITS, (s1_ptr)_10589);
    Concat((object_ptr)&_20START_NUMERIC, _20DIGITS, (s1_ptr)_10591);
    RefDS(_10606);
    _20ESCAPE_CHARS = _10606;
    RefDS(_10607);
    _20ESCAPED_CHARS = _10607;

    // wat_option = FALSE
    _19wat_option = 0;

    // djg_option = FALSE
    _19djg_option = 0;

    // bor_option = FALSE
    _19bor_option = 0;

    // lcc_option = FALSE 
    _19lcc_option = 0;

    // main()
    _21main();
    Cleanup(0);
}
