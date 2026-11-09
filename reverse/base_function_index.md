# Function index

Generated from `analysis/asm_named.txt` by `tools/gen_function_index.py`.

Ghidra 11.3.1, language `STM8:BE:16`, base 0x8000. Coverage 3626 instructions / 394 functions / 93% of image bytes.

`ins` = instructions in the function, `calls` = distinct direct call/jump targets. Empty role = not yet identified.

| addr | name | ins | calls | role |
|---|---|---|---|---|
| 0x8000 | `VEC00_RESET` | 1 | 0 |  |
| 0x8080 | `x_8080` | 65 | 13 | message post (types 0x17/0x18/0x1B seen) |
| 0x8112 | `sub_8112` | 3 | 0 |  |
| 0x8118 | `sub_8118` | 3 | 0 |  |
| 0x811E | `sub_811e` | 18 | 1 |  |
| 0x8146 | `sub_8146` | 18 | 4 |  |
| 0x816D | `x_816d` | 43 | 7 | event decoder (maps 1,3,5,7 -> 0,2,4,6) |
| 0x81CD | `sub_81cd` | 85 | 7 |  |
| 0x828D | `sub_828d` | 1 | 0 |  |
| 0x828E | `sub_828e` | 12 | 3 |  |
| 0x82A8 | `sub_82a8` | 1 | 0 |  |
| 0x82AA | `sub_82aa` | 4 | 1 |  |
| 0x82B3 | `sub_82b3` | 69 | 6 |  |
| 0x833B | `x_833b` | 129 | 11 |  |
| 0x845D | `sub_845d` | 1 | 0 |  |
| 0x845E | `sub_845e` | 16 | 4 |  |
| 0x8480 | `sub_8480` | 4 | 0 |  |
| 0x8485 | `sub_8485` | 5 | 0 |  |
| 0x848B | `sub_848b` | 3 | 0 |  |
| 0x8490 | `sub_8490` | 2 | 0 |  |
| 0x8495 | `sub_8495` | 7 | 0 |  |
| 0x84A5 | `sub_84a5` | 8 | 0 |  |
| 0x84B3 | `sub_84b3` | 3 | 1 |  |
| 0x84B9 | `sub_84b9` | 7 | 2 |  |
| 0x84C5 | `sub_84c5` | 5 | 1 |  |
| 0x84CC | `sub_84cc` | 4 | 2 |  |
| 0x84D5 | `sub_84d5` | 8 | 0 |  |
| 0x84E4 | `sub_84e4` | 17 | 1 |  |
| 0x8504 | `sub_8504` | 11 | 0 |  |
| 0x851A | `sub_851a` | 94 | 8 |  |
| 0x85E6 | `sub_86a6` | 13 | 3 |  |
| 0x860C | `sub_860c` | 27 | 4 |  |
| 0x8640 | `sub_8640` | 30 | 3 |  |
| 0x8689 | `sub_8689` | 11 | 1 |  |
| 0x86A6 | `sub_86a6` | 2 | 1 |  |
| 0x86AB | `sub_86ab` | 11 | 0 |  |
| 0x86C2 | `sub_86c2` | 2 | 1 |  |
| 0x86C8 | `sub_86c8` | 2 | 0 |  |
| 0x86CB | `sub_86cb` | 3 | 0 |  |
| 0x86D1 | `sub_86d1` | 1 | 0 |  |
| 0x86D3 | `sub_86d3` | 3 | 0 |  |
| 0x86D8 | `sub_86d8` | 3 | 1 |  |
| 0x86DF | `sub_86df` | 3 | 0 |  |
| 0x86E8 | `sub_86e8` | 9 | 2 |  |
| 0x8700 | `ret_8700` | 117 | 7 |  |
| 0x8811 | `sub_8811` | 2 | 0 |  |
| 0x8814 | `sub_8814` | 3 | 1 |  |
| 0x881C | `sub_881c` | 5 | 1 |  |
| 0x8828 | `sub_8828` | 9 | 2 |  |
| 0x8841 | `x_8841` | 198 | 32 |  |
| 0x8A15 | `sub_8a15` | 20 | 9 |  |
| 0x8A46 | `sub_8a46` | 118 | 23 |  |
| 0x8B5D | `sub_8b5d` | 7 | 3 |  |
| 0x8B6E | `sub_8b6e` | 1 | 1 |  |
| 0x8B71 | `sub_8b71` | 3 | 1 |  |
| 0x8B79 | `sub_8b79` | 7 | 1 |  |
| 0x8B8A | `sub_8b8a` | 1 | 0 |  |
| 0x8B8E | `sub_8b8e` | 3 | 1 |  |
| 0x8B96 | `sub_8b96` | 72 | 2 |  |
| 0x8C31 | `x_8c31` | 103 | 6 |  |
| 0x8D00 | `sub_8d00` | 2 | 0 |  |
| 0x8D03 | `sub_8d03` | 10 | 0 |  |
| 0x8D16 | `sub_8d16` | 14 | 0 |  |
| 0x8D31 | `sub_8d31` | 72 | 1 |  |
| 0x8DBB | `sub_8dbb` | 2 | 1 |  |
| 0x8DC0 | `sub_8dc0` | 1 | 1 |  |
| 0x8DC3 | `sub_8dc3` | 54 | 0 |  |
| 0x8E30 | `sub_8e30` | 8 | 0 |  |
| 0x8E40 | `sub_8e40` | 10 | 0 |  |
| 0x8E51 | `sub_8e51` | 7 | 0 |  |
| 0x8E5C | `sub_8e5c` | 50 | 19 |  |
| 0x8EE6 | `sub_8ee6` | 57 | 9 |  |
| 0x8F7E | `x_8f7e` | 20 | 2 |  |
| 0x8FB5 | `x_8fb5` | 82 | 16 |  |
| 0x908A | `x_908a` | 3 | 0 | flag/critical-section helper |
| 0x908F | `sub_908f` | 3 | 0 |  |
| 0x9094 | `sub_9094` | 3 | 0 |  |
| 0x9099 | `FUN_9099` | 14 | 0 |  |
| 0x90AC | `sub_90ac` | 4 | 0 |  |
| 0x90B3 | `sub_90b3` | 4 | 0 |  |
| 0x90BA | `FUN_90ba` | 5 | 0 |  |
| 0x90C2 | `sub_90c2` | 3 | 0 |  |
| 0x90C7 | `sub_90c7` | 3 | 0 |  |
| 0x90CC | `sub_90cc` | 3 | 0 |  |
| 0x90D1 | `sub_90d1` | 3 | 0 |  |
| 0x90D6 | `FUN_90d6` | 21 | 0 |  |
| 0x90F3 | `sub_90f3` | 6 | 0 |  |
| 0x90FE | `sub_90fe` | 6 | 0 |  |
| 0x9109 | `sub_9109` | 6 | 0 |  |
| 0x9114 | `sub_9114` | 6 | 0 |  |
| 0x911F | `FUN_911f` | 5 | 0 |  |
| 0x9127 | `sub_9127` | 1 | 1 |  |
| 0x912A | `sub_912a` | 2 | 1 |  |
| 0x912E | `sub_912e` | 3 | 2 |  |
| 0x9135 | `sub_9135` | 2 | 1 |  |
| 0x9139 | `sub_9139` | 3 | 0 |  |
| 0x9140 | `sub_9140` | 3 | 0 |  |
| 0x9147 | `sub_9147` | 5 | 0 |  |
| 0x9154 | `sub_9154` | 5 | 0 |  |
| 0x9161 | `sub_9161` | 5 | 0 |  |
| 0x916E | `sub_916e` | 5 | 0 |  |
| 0x917B | `sub_917b` | 70 | 2 |  |
| 0x9223 | `vec_9223` | 60 | 10 |  |
| 0x92C2 | `gap_92c2` | 68 | 11 |  |
| 0x935E | `ret_935e` | 59 | 5 |  |
| 0x93E5 | `sub_93e5` | 52 | 0 |  |
| 0x9464 | `clk_set_divider` | 47 | 5 | clock divider set |
| 0x94D6 | `sub_94d6` | 40 | 6 |  |
| 0x9541 | `sub_9541` | 54 | 0 |  |
| 0x95A5 | `sub_95a5` | 12 | 0 |  |
| 0x95B5 | `sub_95b5` | 8 | 0 |  |
| 0x95C1 | `sub_95c1` | 8 | 0 |  |
| 0x95CD | `sub_95cd` | 12 | 0 |  |
| 0x95DE | `x_95de` | 7 | 0 |  |
| 0x95EC | `sub_95ec` | 7 | 0 |  |
| 0x95FA | `sub_95fa` | 7 | 0 |  |
| 0x9608 | `vec_9608` | 38 | 10 |  |
| 0x966A | `sub_966a` | 46 | 1 |  |
| 0x96CB | `itc_set_priority` | 40 | 8 | interrupt priority (ITC_SPR1/2) |
| 0x9728 | `sub_9728` | 43 | 1 |  |
| 0x9780 | `uart1_set_control_bits` | 39 | 2 | UART1 control-bit set/clear by index+mask |
| 0x97D3 | `vec_97d3` | 29 | 9 |  |
| 0x9823 | `sub_9823` | 34 | 1 |  |
| 0x9872 | `sub_9872` | 29 | 7 |  |
| 0x98B6 | `sub_98b6` | 32 | 1 |  |
| 0x98F1 | `clk_gate_enable_1` | 14 | 0 | peripheral clock gate 1 |
| 0x9927 | `sub_9927` | 24 | 4 |  |
| 0x995A | `sub_995a` | 28 | 0 |  |
| 0x998A | `gap_998a` | 16 | 1 |  |
| 0x99B6 | `sub_99b6` | 20 | 0 |  |
| 0x99D4 | `sub_99d4` | 6 | 0 |  |
| 0x99DC | `sub_99dc` | 5 | 0 |  |
| 0x99E1 | `vec_99e1` | 14 | 8 |  |
| 0x9A0B | `sub_9a0b` | 16 | 7 |  |
| 0x9A34 | `ret_9a34` | 29 | 0 |  |
| 0x9A5C | `ret_9a5c` | 19 | 0 |  |
| 0x9A84 | `sub_9a84` | 16 | 1 |  |
| 0x9AAA | `sub_9aaa` | 7 | 1 |  |
| 0x9AB7 | `sub_9ab7` | 7 | 1 |  |
| 0x9AC4 | `sub_9ac4` | 5 | 0 |  |
| 0x9ACF | `sub_9acf` | 14 | 7 |  |
| 0x9AF3 | `sub_9af3` | 17 | 1 |  |
| 0x9B17 | `sub_9b17` | 15 | 2 |  |
| 0x9B3A | `sub_9b3a` | 12 | 7 |  |
| 0x9B72 | `sub_9b72` | 11 | 4 |  |
| 0x9B92 | `sub_9b92` | 16 | 1 | block copy (dest X, src Y, len g_0008) |
| 0x9BCF | `x_9bcf` | 14 | 1 |  |
| 0x9BEB | `sub_9beb` | 11 | 0 |  |
| 0x9C03 | `sub_9c03` | 11 | 0 |  |
| 0x9C1B | `sub_9c1b` | 8 | 0 |  |
| 0x9C31 | `x_9c31` | 12 | 0 |  |
| 0x9C47 | `sub_9c47` | 10 | 0 |  |
| 0x9C5B | `x_9c5b` | 10 | 2 |  |
| 0x9C6F | `sub_9c6f` | 4 | 1 |  |
| 0x9C76 | `flash_write_key_ae` | 5 | 1 | flash key 0xAE write |
| 0x9C82 | `flash_write_key_56` | 8 | 4 | flash key 0x56 write |
| 0x9C95 | `sub_9c95` | 7 | 4 |  |
| 0x9CA7 | `sub_9ca7` | 8 | 2 |  |
| 0x9CB8 | `sub_9cb8` | 8 | 1 |  |
| 0x9CC8 | `sub_9cc8` | 6 | 0 |  |
| 0x9CD2 | `sub_9cd2` | 5 | 0 |  |
| 0x9CD8 | `reset_startup` | 5 | 2 | reset/startup: SP=0x03FF, init calls, jump to main |
| 0x9CE7 | `sub_9ce7` | 4 | 0 |  |
| 0x9CF6 | `sub_9cf6` | 8 | 0 |  |
| 0x9D05 | `sub_9d05` | 7 | 2 |  |
| 0x9D14 | `sub_9d14` | 7 | 2 |  |
| 0x9D23 | `sub_9d23` | 6 | 0 |  |
| 0x9D32 | `sub_9d32` | 8 | 0 |  |
| 0x9D40 | `sub_9d40` | 6 | 2 |  |
| 0x9D4E | `sub_9d4e` | 6 | 1 |  |
| 0x9D5C | `sub_9d5c` | 7 | 2 |  |
| 0x9D69 | `sub_9d69` | 6 | 1 |  |
| 0x9D76 | `sub_9d76` | 6 | 0 |  |
| 0x9D83 | `sub_9d83` | 6 | 0 |  |
| 0x9D90 | `sub_9d90` | 6 | 0 |  |
| 0x9D9D | `sub_9d9d` | 6 | 0 |  |
| 0x9DAA | `clk_gate_enable_2` | 9 | 0 | peripheral clock gate 2 |
| 0x9DB7 | `sub_9db7` | 7 | 0 |  |
| 0x9DC3 | `sub_9dc3` | 5 | 0 |  |
| 0x9DCF | `sub_9dcf` | 3 | 0 |  |
| 0x9DDA | `sub_9dda` | 5 | 0 |  |
| 0x9DE5 | `sub_9de5` | 5 | 1 |  |
| 0x9DEF | `tim4_init` | 4 | 0 |  |
| 0x9DF9 | `sub_9df9` | 4 | 0 |  |
| 0x9E03 | `sub_9e03` | 1 | 0 |  |
| 0x9E05 | `sub_9e05` | 3 | 1 |  |
| 0x9E0D | `sub_9e0d` | 5 | 0 |  |
| 0x9E17 | `sub_9e17` | 4 | 0 |  |
| 0x9E21 | `sub_9e21` | 7 | 0 |  |
| 0x9E2B | `gap_9e2b` | 3 | 2 |  |
| 0x9E34 | `sub_9e34` | 6 | 0 |  |
| 0x9E3D | `sub_9e3d` | 2 | 0 |  |
| 0x9E40 | `sub_9e40` | 3 | 0 |  |
| 0x9E46 | `sub_9e46` | 6 | 0 |  |
| 0x9E4F | `sub_9e4f` | 4 | 0 |  |
| 0x9E58 | `sub_9e58` | 3 | 0 |  |
| 0x9E61 | `sub_9e61` | 5 | 0 |  |
| 0x9E6A | `sub_9e6a` | 5 | 0 |  |
| 0x9E73 | `sub_9e73` | 4 | 0 |  |
| 0x9E7C | `sub_9e7c` | 6 | 1 |  |
| 0x9E85 | `gap_9e85` | 4 | 0 |  |
| 0x9E8D | `sub_9e8d` | 6 | 0 |  |
| 0x9E95 | `sub_9e95` | 4 | 1 |  |
| 0x9E9D | `sub_9e9d` | 4 | 1 |  |
| 0x9EA5 | `sub_9ea5` | 4 | 0 |  |
| 0x9EAC | `clk_gate_enable_3` | 4 | 0 | peripheral clock gate 3 |
| 0x9EB3 | `sub_9eb3` | 4 | 1 |  |
| 0x9EBA | `FUN_9eba` | 5 | 0 |  |
| 0x9EC1 | `tim2_set_ccr1l` | 5 | 0 | TIM2 CCR1L write (PWM duty) |
| 0x9EC8 | `sub_9ec8` | 6 | 0 |  |
| 0x9ECF | `tim4_clear_egr` | 3 | 1 |  |
| 0x9ED6 | `sub_9ed6` | 3 | 0 |  |
| 0x9EDC | `sub_9edc` | 2 | 0 |  |
| 0x9EE1 | `sub_9ee1` | 2 | 0 |  |
| 0x9EE6 | `sub_9ee6` | 3 | 0 |  |
| 0x9EEB | `sub_9eeb` | 3 | 0 |  |
| 0x9EF0 | `sub_9ef0` | 3 | 0 |  |
| 0x9EF5 | `sub_9ef5` | 6 | 1 |  |
| 0x9EFE | `sub_9efe` | 2 | 1 |  |
| 0x9F02 | `sub_9f02` | 2 | 1 |  |
| 0x9F06 | `sub_9f06` | 2 | 1 |  |
| 0x9F0A | `sub_9f0a` | 3 | 0 |  |
| 0x9F0E | `sub_9f0e` | 3 | 0 |  |
| 0x9F12 | `FUN_9f12` | 4 | 0 |  |
| 0x9F16 | `sub_9f16` | 2 | 0 |  |
| 0x9F1A | `sub_9f1a` | 2 | 0 |  |
| 0x9F1E | `sub_9f1e` | 2 | 0 |  |
| 0x9F22 | `sub_9f22` | 2 | 0 | enable interrupts (clear I1) |
| 0x9F26 | `sub_9f26` | 2 | 0 | interrupt helper (CC bit) |
| 0x9F2A | `thunk_FUN_9f12` | 1 | 1 |  |
| 0x9F2D | `thunk_FUN_9eba` | 1 | 1 |  |
| 0x9F30 | `thunk_FUN_9f39` | 1 | 1 |  |
| 0x9F33 | `sub_9f33` | 3 | 0 |  |
| 0x9F36 | `iwdg_reload` | 1 | 1 | IWDG refresh |
| 0x9F39 | `FUN_9f39` | 2 | 0 |  |
| 0x9F3C | `vec_9f3c` | 1 | 0 |  |
| 0x9F3D | `iwdg_start` | 1 | 0 | IWDG start (KR=0xCC) |
| 0x9F3E | `vec_9f3e` | 1 | 0 |  |
| 0x9F3F | `vec_9f3f` | 1 | 0 |  |
| 0x9F40 | `vec_9f40` | 1 | 0 |  |
| 0x9F41 | `vec_9f41` | 1 | 0 |  |
| 0x9F42 | `vec_9f42` | 1 | 0 |  |
| 0x9F43 | `vec_9f43` | 1 | 0 |  |
| 0x9F44 | `vec_9f44` | 1 | 0 |  |
| 0x9F45 | `vec_9f45` | 1 | 0 |  |
| 0x9F46 | `vec_9f46` | 1 | 0 |  |
| 0x9F47 | `vec_9f47` | 1 | 0 |  |
| 0x9F48 | `vec_9f48` | 1 | 0 |  |
| 0x9F49 | `vec_9f49` | 1 | 0 |  |
| 0x9F4A | `vec_9f4a` | 1 | 0 |  |
| 0x9F4B | `sub_9f4b` | 1 | 0 |  |
| 0x9F4C | `gap_9f4c` | 17 | 0 |  |
| 0x9F5D | `gap_9f5d` | 17 | 0 |  |
| 0x9F6E | `gap_9f6e` | 17 | 0 |  |
| 0x9F7F | `gap_9f7f` | 17 | 0 |  |
| 0x9F90 | `gap_9f90` | 17 | 0 |  |
