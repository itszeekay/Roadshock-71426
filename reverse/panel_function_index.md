# Function index

Generated from `analysis/asm_named.txt` by `tools/gen_function_index.py`.

Ghidra 11.3.1, language `STM8:BE:16`, base 0x8000. Coverage 3626 instructions / 394 functions / 93% of image bytes.

`ins` = instructions in the function, `calls` = distinct direct call/jump targets. Empty role = not yet identified.

| addr | name | ins | calls | role |
|---|---|---|---|---|
| 0x8000 | `VEC00_RESET` | 1 | 0 |  |
| 0x8018 | `VEC06_EXTI1` | 1 | 0 |  |
| 0x801C | `VEC07_EXTI2` | 1 | 0 |  |
| 0x8080 | `x_8080` | 100 | 4 | message post (types 0x17/0x18/0x1B seen) |
| 0x816D | `x_816d` | 78 | 18 | event decoder (maps 1,3,5,7 -> 0,2,4,6) |
| 0x8237 | `sub_8237` | 14 | 0 |  |
| 0x8252 | `sub_8252` | 72 | 1 |  |
| 0x82DC | `sub_82dc` | 2 | 1 |  |
| 0x82E1 | `sub_82e1` | 1 | 1 |  |
| 0x82E4 | `sub_82e4` | 54 | 0 |  |
| 0x8351 | `sub_8351` | 10 | 0 |  |
| 0x8362 | `sub_8362` | 3 | 0 |  |
| 0x8367 | `sub_8367` | 3 | 0 |  |
| 0x836C | `FUN_836c` | 14 | 0 |  |
| 0x837F | `sub_837f` | 9 | 0 |  |
| 0x838E | `sub_838e` | 3 | 0 |  |
| 0x8393 | `sub_8393` | 3 | 0 |  |
| 0x8398 | `sub_8398` | 3 | 0 |  |
| 0x839D | `sub_839d` | 3 | 0 |  |
| 0x83A2 | `FUN_83a2` | 21 | 0 |  |
| 0x83BF | `sub_83bf` | 6 | 0 |  |
| 0x83CA | `sub_83ca` | 6 | 0 |  |
| 0x83D5 | `sub_83d5` | 6 | 0 |  |
| 0x83E0 | `sub_83e0` | 6 | 0 |  |
| 0x83EB | `FUN_83eb` | 5 | 0 |  |
| 0x83F3 | `sub_83f3` | 1 | 1 |  |
| 0x83F6 | `sub_83f6` | 2 | 1 |  |
| 0x83FA | `sub_83fa` | 2 | 1 |  |
| 0x83FE | `sub_83fe` | 5 | 0 |  |
| 0x840B | `sub_840b` | 5 | 0 |  |
| 0x8418 | `sub_8418` | 5 | 0 |  |
| 0x8425 | `sub_8425` | 5 | 0 |  |
| 0x8432 | `sub_8432` | 5 | 0 |  |
| 0x843F | `sub_843f` | 5 | 0 |  |
| 0x844C | `sub_844c` | 90 | 9 |  |
| 0x8508 | `sub_8508` | 3 | 1 |  |
| 0x8510 | `sub_8510` | 88 | 3 |  |
| 0x85C1 | `sub_85c1` | 64 | 4 |  |
| 0x8841 | `x_8841` | 73 | 0 |  |
| 0x896D | `sub_896d` | 49 | 17 |  |
| 0x89EF | `sub_89ef` | 38 | 3 |  |
| 0x8A52 | `sub_8a52` | 42 | 6 |  |
| 0x8AB4 | `ret_8ab4` | 9 | 0 |  |
| 0x8AC3 | `ret_8ac3` | 1 | 0 |  |
| 0x8AF0 | `ret_8af0` | 17 | 0 |  |
| 0x8B0C | `vec_8b0c` | 34 | 8 |  |
| 0x8B62 | `sub_8b62` | 12 | 0 |  |
| 0x8B72 | `sub_8b72` | 8 | 0 |  |
| 0x8B7E | `sub_8b7e` | 8 | 0 |  |
| 0x8B8A | `sub_8b8a` | 19 | 0 |  |
| 0x8BA9 | `sub_8ba9` | 32 | 1 |  |
| 0x8BE4 | `sub_8be4` | 26 | 3 |  |
| 0x8C1E | `sub_8c1e` | 8 | 2 |  |
| 0x8C31 | `x_8c31` | 14 | 2 |  |
| 0x8C52 | `sub_8c52` | 19 | 3 |  |
| 0x8C81 | `sub_8c81` | 12 | 0 |  |
| 0x8CAC | `sub_8cac` | 17 | 3 |  |
| 0x8CD6 | `sub_8cd6` | 17 | 2 |  |
| 0x8D26 | `sub_8d26` | 17 | 3 |  |
| 0x8D4D | `vec_8d4d` | 17 | 5 |  |
| 0x8D74 | `sub_8d74` | 7 | 1 |  |
| 0x8D81 | `sub_8d81` | 7 | 1 |  |
| 0x8D8E | `sub_8d8e` | 5 | 0 |  |
| 0x8DA3 | `sub_8da3` | 11 | 1 |  |
| 0x8DBD | `sub_8dbd` | 11 | 1 |  |
| 0x8DD6 | `sub_8dd6` | 11 | 1 |  |
| 0x8DEF | `sub_8def` | 10 | 1 |  |
| 0x8E05 | `sub_8e05` | 12 | 0 |  |
| 0x8E1B | `sub_8e1b` | 10 | 0 |  |
| 0x8E2F | `sub_8e2f` | 10 | 2 |  |
| 0x8E43 | `vec_8e43` | 8 | 4 |  |
| 0x8E56 | `sub_8e56` | 7 | 1 |  |
| 0x8E65 | `sub_8e65` | 5 | 1 |  |
| 0x8E72 | `sub_8e72` | 7 | 0 |  |
| 0x8E7F | `sub_8e7f` | 7 | 0 |  |
| 0x8E8C | `sub_8e8c` | 6 | 0 |  |
| 0x8E99 | `sub_8e99` | 6 | 0 |  |
| 0x8EA1 | `sub_8ea1` | 5 | 0 |  |
| 0x8EA6 | `sub_8ea6` | 7 | 0 |  |
| 0x8EB1 | `sub_8eb1` | 5 | 1 |  |
| 0x8EBC | `sub_8ebc` | 5 | 1 |  |
| 0x8EC7 | `sub_8ec7` | 5 | 1 |  |
| 0x8ED2 | `sub_8ed2` | 5 | 1 |  |
| 0x8EDD | `sub_8edd` | 5 | 1 |  |
| 0x8EE8 | `sub_8ee8` | 5 | 1 |  |
| 0x8EF3 | `sub_8ef3` | 6 | 0 |  |
| 0x8EFD | `sub_8efd` | 6 | 0 |  |
| 0x8F06 | `sub_8f06` | 4 | 1 |  |
| 0x8F0F | `sub_8f0f` | 4 | 0 |  |
| 0x8F18 | `sub_8f18` | 6 | 1 |  |
| 0x8F21 | `sub_8f21` | 4 | 1 |  |
| 0x8F29 | `sub_8f29` | 3 | 2 |  |
| 0x8F31 | `sub_8f31` | 5 | 0 |  |
| 0x8F38 | `sub_8f38` | 2 | 2 |  |
| 0x8F3E | `sub_8f3e` | 2 | 2 |  |
| 0x8F44 | `sub_8f44` | 2 | 2 |  |
| 0x8F4A | `sub_8f4a` | 3 | 1 |  |
| 0x8F50 | `FUN_8f50` | 6 | 1 |  |
| 0x8F59 | `sub_8f59` | 4 | 0 |  |
| 0x8F5D | `sub_8f5d` | 2 | 0 |  |
| 0x8F61 | `sub_8f61` | 2 | 0 |  |
| 0x8F65 | `sub_8f65` | 1 | 1 |  |
| 0x8F68 | `sub_8f68` | 1 | 1 |  |
| 0x8F6B | `sub_8f6b` | 3 | 0 |  |
| 0x8F6E | `thunk_FUN_8f77` | 1 | 1 |  |
| 0x8F71 | `sub_8f71` | 3 | 0 |  |
| 0x8F74 | `thunk_FUN_8f50` | 1 | 1 |  |
| 0x8F77 | `FUN_8f77` | 2 | 0 |  |
| 0x8F7A | `sub_8f7a` | 1 | 0 |  |
| 0x8F7C | `vec_8f7c` | 1 | 0 |  |
| 0x8F7D | `vec_8f7d` | 1 | 0 |  |
| 0x8F7E | `vec_8f7e` | 1 | 0 |  |
| 0x8F7F | `vec_8f7f` | 1 | 0 |  |
| 0x8F80 | `vec_8f80` | 1 | 0 |  |
| 0x8F81 | `vec_8f81` | 1 | 0 |  |
| 0x8F82 | `vec_8f82` | 1 | 0 |  |
| 0x8F83 | `vec_8f83` | 1 | 0 |  |
| 0x8F84 | `vec_8f84` | 1 | 0 |  |
| 0x8F85 | `vec_8f85` | 1 | 0 |  |
| 0x8F86 | `vec_8f86` | 1 | 0 |  |
| 0x8F87 | `vec_8f87` | 1 | 0 |  |
| 0x8F88 | `vec_8f88` | 1 | 0 |  |
| 0x8F89 | `vec_8f89` | 1 | 0 |  |
| 0x8F8A | `vec_8f8a` | 1 | 0 |  |
| 0x8F8B | `vec_8f8b` | 1 | 0 |  |
| 0x8F8C | `vec_8f8c` | 1 | 0 |  |
| 0x8F8D | `vec_8f8d` | 1 | 0 |  |
| 0x8F8E | `sub_8f8e` | 1 | 0 |  |
| 0x8F8F | `gap_8f8f` | 17 | 0 |  |
| 0x8FA0 | `gap_8fa0` | 9 | 0 |  |
| 0x8FA9 | `uart1_configure` | 12 | 0 | UART1 configure (CR1/CR3/BRR1/BRR2/CR2) |
| 0x8FB5 | `x_8fb5` | 5 | 0 |  |
| 0x8FBA | `gap_8fba` | 17 | 0 |  |
| 0x8FCB | `gap_8fcb` | 17 | 0 |  |
| 0x8FDC | `gap_8fdc` | 17 | 0 |  |
| 0x8FED | `gap_8fed` | 17 | 0 |  |
| 0x8FFE | `gap_8ffe` | 19 | 0 |  |
| 0x908A | `x_908a` | 17 | 0 | flag/critical-section helper |
| 0x9510 | `x_9510` | 17 | 0 |  |
| 0x95DE | `x_95de` | 17 | 0 |  |
| 0x9780 | `uart1_set_control_bits` | 17 | 0 | UART1 control-bit set/clear by index+mask |
| 0x97D3 | `x_97d3` | 17 | 0 |  |
| 0x9824 | `x_9824` | 17 | 0 |  |
| 0x9BCF | `x_9bcf` | 17 | 0 |  |
| 0x9C31 | `x_9c31` | 17 | 0 |  |
| 0x9C5B | `x_9c5b` | 17 | 0 |  |
| 0x9CD8 | `reset_startup` | 17 | 0 | reset/startup: SP=0x03FF, init calls, jump to main |
