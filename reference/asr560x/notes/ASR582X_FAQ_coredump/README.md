# ASR582X FAQ, coredump section

This is an ASR582X page in an ASR560X archive for one reason: it is the only ASR
document found so far that names the command behind DOGO's read path.

Section 4.8 of the page says, in Chinese:

1. Create a `coredump` folder inside `recev_data` beside the DOGO tool.
2. Connect the module's UART1 log port and open it in DOGO.
3. Check `Coredump` and the received-file option.
4. Enter `coredump flash all` and wait.
5. Collect the `.bin` files from `recev_data/coredump`.

The DOGO code in `../drive/DOGO_extract/` confirms the host side: it captures
`:<ten-character label><hex>$` lines and writes one `.bin` per label.

The command is documented for ASR582X, not ASR560X. It is the first command to
try on the ASR5601S monitor. If the monitor rejects it, the fallback is the same
command on the running app's UART1, then SWD.

Source:

- https://asriot-cn.readthedocs.io/zh/latest/ASR582X/常见问题/582X_开发常见问题.html
- rst twin: https://asriot-cn.readthedocs.io/zh/latest/_sources/ASR582X/常见问题/582X_开发常见问题.rst.txt

The files are unchanged copies, kept because ASR's readthedocs sites may go
offline. Copyright remains ASR Microelectronics Co., Ltd.
