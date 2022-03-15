# Odpowiedzi do zadań 1.c 1.d oraz 1.e
> Autor: Tymoteusz Białkowski

## Podpunkt C
Zrzut z pstree

systemd(1)─┬─ModemManager(738)─┬─{ModemManager}(756)
           │                   └─{ModemManager}(759)
           ├─NetworkManager(636)─┬─{NetworkManager}(743)
           │                     └─{NetworkManager}(773)
           ├─accounts-daemon(628)─┬─{accounts-daemon}(654)
           │                      └─{accounts-daemon}(728)
           ├─acpid(629)
           ├─avahi-daemon(632)───avahi-daemon(674)
           ├─colord(1392)─┬─{colord}(1417)
           │              └─{colord}(1419)
           ├─cron(633)
           ├─cups-browsed(733)─┬─{cups-browsed}(744)
           │                   └─{cups-browsed}(745)
           ├─cupsd(718)
           ├─dbus-daemon(635)
           ├─fwupd(1588)─┬─{fwupd}(1589)
           │             ├─{fwupd}(1590)
           │             ├─{fwupd}(1591)
           │             └─{fwupd}(1593)
           ├─gdm3(798)─┬─gdm-session-wor(807)─┬─gdm-x-session(922)─┬─Xorg(925)─+++
           │           │                      │                    ├─gnome-sess+
           │           │                      │                    ├─{gdm-x-ses+
           │           │                      │                    └─{gdm-x-ses+
           │           │                      ├─{gdm-session-wor}(809)
           │           │                      └─{gdm-session-wor}(811)
           │           ├─{gdm3}(803)
           │           └─{gdm3}(804)
           ├─gnome-keyring-d(917)─┬─{gnome-keyring-d}(918)
           │                      ├─{gnome-keyring-d}(919)
           │                      └─{gnome-keyring-d}(1146)
           ├─irqbalance(653)───{irqbalance}(659)
           ├─kerneloops(835)
           ├─kerneloops(837)
           ├─networkd-dispat(655)
           ├─polkitd(660)─┬─{polkitd}(675)
           │              └─{polkitd}(729)
           ├─rsyslogd(662)─┬─{rsyslogd}(692)
           │               ├─{rsyslogd}(693)
           │               └─{rsyslogd}(694)
           ├─rtkit-daemon(927)─┬─{rtkit-daemon}(928)
           │                   └─{rtkit-daemon}(929)
           ├─snapd(663)─┬─{snapd}(720)
           │            ├─{snapd}(721)
           │            ├─{snapd}(722)
           │            ├─{snapd}(723)
           │            ├─{snapd}(724)
           │            ├─{snapd}(763)
           │            ├─{snapd}(764)
           │            ├─{snapd}(765)
           │            ├─{snapd}(797)
           │            ├─{snapd}(902)
           │            ├─{snapd}(909)
           │            ├─{snapd}(923)
           │            ├─{snapd}(926)
           │            └─{snapd}(1977)
           ├─switcheroo-cont(664)─┬─{switcheroo-cont}(678)
           │                      └─{switcheroo-cont}(730)
           ├─systemd(904)─┬─(sd-pam)(905)
           │              ├─1C.x(6499)
           │              ├─1C.x(6500)
           │              ├─1C.x(6501)
           │              ├─at-spi-bus-laun(1112)─┬─dbus-daemon(1117)
           │              │                       ├─{at-spi-bus-laun}(1113)
           │              │                       ├─{at-spi-bus-laun}(1114)
           │              │                       └─{at-spi-bus-laun}(1115)
           │              ├─at-spi2-registr(1213)─┬─{at-spi2-registr}(1214)
           │              │                       └─{at-spi2-registr}(1215)
           │              ├─code(2214)─┬─code(2216)───code(2252)─┬─{code}(2261)
           │              │            │                         ├─{code}(2262)
           │              │            │                         ├─{code}(2263)
           │              │            │                         ├─{code}(2265)
           │              │            │                         ├─{code}(5692)
           │              │            │                         ├─{code}(6207)
           │              │            │                         ├─{code}(6208)
           │              │            │                         ├─{code}(6209)
           │              │            │                         └─{code}(6210)
           │              │            ├─code(2217)
           │              │            ├─code(2256)─┬─{code}(2257)
           │              │            │            ├─{code}(2259)
           │              │            │            ├─{code}(2267)
           │              │            │            ├─{code}(4926)
           │              │            │            └─{code}(5695)
           │              │            ├─code(2321)─┬─code(2336)─┬─bash(6188)
           │              │            │            │            ├─{code}(2341)
           │              │            │            │            ├─{code}(2342)
           │              │            │            │            ├─{code}(2343)
           │              │            │            │            ├─{code}(2344)
           │              │            │            │            ├─{code}(2345)
           │              │            │            │            ├─{code}(2346)
           │              │            │            │            ├─{code}(2347)
           │              │            │            │            ├─{code}(2360)
           │              │            │            │            ├─{code}(2361)
           │              │            │            │            ├─{code}(2362)
           │              │            │            │            ├─{code}(2363)
           │              │            │            │            └─{code}(6189)
           │              │            │            ├─code(6170)─┬─{code}(6171)
           │              │            │            │            ├─{code}(6172)
           │              │            │            │            ├─{code}(6173)
           │              │            │            │            ├─{code}(6174)
           │              │            │            │            ├─{code}(6175)
           │              │            │            │            ├─{code}(6176)
           │              │            │            │            ├─{code}(6177)
           │              │            │            │            ├─{code}(6180)
           │              │            │            │            ├─{code}(6181)
           │              │            │            │            ├─{code}(6182)
           │              │            │            │            ├─{code}(6183)
           │              │            │            │            ├─{code}(6185)
           │              │            │            │            └─{code}(6186)
           │              │            │            ├─{code}(2322)
           │              │            │            ├─{code}(2324)
           │              │            │            ├─{code}(2326)
           │              │            │            ├─{code}(2328)
           │              │            │            ├─{code}(2329)
           │              │            │            ├─{code}(2330)
           │              │            │            ├─{code}(2331)
           │              │            │            ├─{code}(2332)
           │              │            │            ├─{code}(2333)
           │              │            │            ├─{code}(2337)
           │              │            │            ├─{code}(2338)
           │              │            │            ├─{code}(2339)
           │              │            │            ├─{code}(2340)
           │              │            │            ├─{code}(2367)
           │              │            │            ├─{code}(2368)
           │              │            │            ├─{code}(2369)
           │              │            │            ├─{code}(5696)
           │              │            │            ├─{code}(5767)
           │              │            │            └─{code}(5768)
           │              │            ├─code(6138)─┬─{code}(6143)
           │              │            │            ├─{code}(6144)
           │              │            │            ├─{code}(6145)
           │              │            │            ├─{code}(6146)
           │              │            │            ├─{code}(6147)
           │              │            │            ├─{code}(6148)
           │              │            │            ├─{code}(6149)
           │              │            │            ├─{code}(6150)
           │              │            │            ├─{code}(6151)
           │              │            │            ├─{code}(6152)
           │              │            │            ├─{code}(6153)
           │              │            │            ├─{code}(6154)
           │              │            │            ├─{code}(6178)
           │              │            │            ├─{code}(6179)
           │              │            │            └─{code}(6251)
           │              │            ├─code(6158)─┬─cpptools(6212)─┬─cpptools+
           │              │            │            │                ├─{cpptool+
           │              │            │            │                ├─{cpptool+
           │              │            │            │                ├─{cpptool+
           │              │            │            │                ├─{cpptool+
           │              │            │            │                ├─{cpptool+
           │              │            │            │                ├─{cpptool+
           │              │            │            │                ├─{cpptool+
           │              │            │            │                ├─{cpptool+
           │              │            │            │                ├─{cpptool+
           │              │            │            │                ├─{cpptool+
           │              │            │            │                ├─{cpptool+
           │              │            │            │                ├─{cpptool+
           │              │            │            │                ├─{cpptool+
           │              │            │            │                ├─{cpptool+
           │              │            │            │                ├─{cpptool+
           │              │            │            │                ├─{cpptool+
           │              │            │            │                ├─{cpptool+
           │              │            │            │                ├─{cpptool+
           │              │            │            │                ├─{cpptool+
           │              │            │            │                ├─{cpptool+
           │              │            │            │                ├─{cpptool+
           │              │            │            │                ├─{cpptool+
           │              │            │            │                └─{cpptool+
           │              │            │            ├─{code}(6159)
           │              │            │            ├─{code}(6160)
           │              │            │            ├─{code}(6161)
           │              │            │            ├─{code}(6162)
           │              │            │            ├─{code}(6163)
           │              │            │            ├─{code}(6164)
           │              │            │            ├─{code}(6165)
           │              │            │            ├─{code}(6166)
           │              │            │            ├─{code}(6167)
           │              │            │            ├─{code}(6168)
           │              │            │            ├─{code}(6169)
           │              │            │            └─{code}(6184)
           │              │            ├─{code}(2215)
           │              │            ├─{code}(2218)
           │              │            ├─{code}(2221)
           │              │            ├─{code}(2222)
           │              │            ├─{code}(2223)
           │              │            ├─{code}(2224)
           │              │            ├─{code}(2225)
           │              │            ├─{code}(2226)
           │              │            ├─{code}(2227)
           │              │            ├─{code}(2228)
           │              │            ├─{code}(2229)
           │              │            ├─{code}(2230)
           │              │            ├─{code}(2231)
           │              │            ├─{code}(2234)
           │              │            ├─{code}(2235)
           │              │            ├─{code}(2236)
           │              │            ├─{code}(2237)
           │              │            ├─{code}(2238)
           │              │            ├─{code}(2240)
           │              │            ├─{code}(2241)
           │              │            ├─{code}(2243)
           │              │            ├─{code}(2244)
           │              │            ├─{code}(2245)
           │              │            ├─{code}(2246)
           │              │            ├─{code}(2254)
           │              │            ├─{code}(2255)
           │              │            ├─{code}(2273)
           │              │            ├─{code}(2275)
           │              │            ├─{code}(2276)
           │              │            ├─{code}(2298)
           │              │            ├─{code}(4862)
           │              │            ├─{code}(5690)
           │              │            └─{code}(6155)
           │              ├─dbus-daemon(932)
           │              ├─dconf-service(1423)─┬─{dconf-service}(1429)
           │              │                     └─{dconf-service}(1430)
           │              ├─evolution-addre(1428)─┬─{evolution-addre}(1431)
           │              │                       ├─{evolution-addre}(1432)
           │              │                       ├─{evolution-addre}(1438)
           │              │                       ├─{evolution-addre}(1439)
           │              │                       └─{evolution-addre}(1453)
           │              ├─evolution-calen(1252)─┬─{evolution-calen}(1260)
           │              │                       ├─{evolution-calen}(1261)
           │              │                       ├─{evolution-calen}(1415)
           │              │                       ├─{evolution-calen}(1416)
           │              │                       ├─{evolution-calen}(1424)
           │              │                       ├─{evolution-calen}(1425)
           │              │                       └─{evolution-calen}(1427)
           │              ├─evolution-sourc(1230)─┬─{evolution-sourc}(1231)
           │              │                       ├─{evolution-sourc}(1232)
           │              │                       └─{evolution-sourc}(1233)
           │              ├─gjs(1249)─┬─{gjs}(1254)
           │              │           ├─{gjs}(1255)
           │              │           ├─{gjs}(1256)
           │              │           ├─{gjs}(1257)
           │              │           ├─{gjs}(1258)
           │              │           └─{gjs}(1259)
           │              ├─gnome-session-b(1147)─┬─evolution-alarm(1292)─┬─{ev+
           │              │                       │                       ├─{ev+
           │              │                       │                       ├─{ev+
           │              │                       │                       ├─{ev+
           │              │                       │                       └─{ev+
           │              │                       ├─gsd-disk-utilit(1320)─┬─{gs+
           │              │                       │                       └─{gs+
           │              │                       ├─update-notifier(1996)─┬─{up+
           │              │                       │                       ├─{up+
           │              │                       │                       └─{up+
           │              │                       ├─{gnome-session-b}(1148)
           │              │                       ├─{gnome-session-b}(1149)
           │              │                       └─{gnome-session-b}(1151)
           │              ├─gnome-session-c(1140)───{gnome-session-c}(1144)
           │              ├─gnome-shell(1161)─┬─ibus-daemon(1191)─┬─ibus-engine+
           │              │                   │                   ├─ibus-extens+
           │              │                   │                   ├─ibus-memcon+
           │              │                   │                   ├─{ibus-daemo+
           │              │                   │                   └─{ibus-daemo+
           │              │                   ├─{gnome-shell}(1173)
           │              │                   ├─{gnome-shell}(1175)
           │              │                   ├─{gnome-shell}(1176)
           │              │                   ├─{gnome-shell}(1178)
           │              │                   ├─{gnome-shell}(1179)
           │              │                   ├─{gnome-shell}(1180)
           │              │                   ├─{gnome-shell}(1181)
           │              │                   ├─{gnome-shell}(1182)
           │              │                   ├─{gnome-shell}(1183)
           │              │                   ├─{gnome-shell}(1184)
           │              │                   ├─{gnome-shell}(1185)
           │              │                   ├─{gnome-shell}(1186)
           │              │                   ├─{gnome-shell}(1187)
           │              │                   ├─{gnome-shell}(1188)
           │              │                   ├─{gnome-shell}(1189)
           │              │                   ├─{gnome-shell}(1190)
           │              │                   └─{gnome-shell}(3151)
           │              ├─gnome-shell-cal(1222)─┬─{gnome-shell-cal}(1225)
           │              │                       ├─{gnome-shell-cal}(1227)
           │              │                       ├─{gnome-shell-cal}(1228)
           │              │                       ├─{gnome-shell-cal}(1229)
           │              │                       └─{gnome-shell-cal}(1251)
           │              ├─gnome-terminal-(6429)─┬─bash(6440)───pstree(6503)
           │              │                       ├─{gnome-terminal-}(6433)
           │              │                       ├─{gnome-terminal-}(6434)
           │              │                       ├─{gnome-terminal-}(6435)
           │              │                       └─{gnome-terminal-}(6439)
           │              ├─goa-daemon(971)─┬─{goa-daemon}(975)
           │              │                 ├─{goa-daemon}(977)
           │              │                 └─{goa-daemon}(978)
           │              ├─goa-identity-se(981)─┬─{goa-identity-se}(987)
           │              │                      └─{goa-identity-se}(989)
           │              ├─gsd-a11y-settin(1264)─┬─{gsd-a11y-settin}(1315)
           │              │                       ├─{gsd-a11y-settin}(1317)
           │              │                       └─{gsd-a11y-settin}(1358)
           │              ├─gsd-color(1265)─┬─{gsd-color}(1347)
           │              │                 ├─{gsd-color}(1352)
           │              │                 └─{gsd-color}(1362)
           │              ├─gsd-datetime(1266)─┬─{gsd-datetime}(1360)
           │              │                    ├─{gsd-datetime}(1365)
           │              │                    └─{gsd-datetime}(1388)
           │              ├─gsd-housekeepin(1268)─┬─{gsd-housekeepin}(1301)
           │              │                       ├─{gsd-housekeepin}(1322)
           │              │                       └─{gsd-housekeepin}(1377)
           │              ├─gsd-keyboard(1270)─┬─{gsd-keyboard}(1321)
           │              │                    ├─{gsd-keyboard}(1327)
           │              │                    └─{gsd-keyboard}(1361)
           │              ├─gsd-media-keys(1271)─┬─{gsd-media-keys}(1328)
           │              │                      ├─{gsd-media-keys}(1329)
           │              │                      └─{gsd-media-keys}(1394)
           │              ├─gsd-power(1272)─┬─{gsd-power}(1331)
           │              │                 ├─{gsd-power}(1344)
           │              │                 └─{gsd-power}(1397)
           │              ├─gsd-print-notif(1275)─┬─{gsd-print-notif}(1304)
           │              │                       └─{gsd-print-notif}(1323)
           │              ├─gsd-printer(1381)─┬─{gsd-printer}(1383)
           │              │                   └─{gsd-printer}(1384)
           │              ├─gsd-rfkill(1276)─┬─{gsd-rfkill}(1299)
           │              │                  └─{gsd-rfkill}(1308)
           │              ├─gsd-screensaver(1277)─┬─{gsd-screensaver}(1305)
           │              │                       └─{gsd-screensaver}(1307)
           │              ├─gsd-sharing(1278)─┬─{gsd-sharing}(1296)
           │              │                   ├─{gsd-sharing}(1313)
           │              │                   └─{gsd-sharing}(1330)
           │              ├─gsd-smartcard(1279)─┬─{gsd-smartcard}(1312)
           │              │                     ├─{gsd-smartcard}(1316)
           │              │                     ├─{gsd-smartcard}(1336)
           │              │                     └─{gsd-smartcard}(1346)
           │              ├─gsd-sound(1280)─┬─{gsd-sound}(1310)
           │              │                 ├─{gsd-sound}(1318)
           │              │                 └─{gsd-sound}(1350)
           │              ├─gsd-usb-protect(1281)─┬─{gsd-usb-protect}(1303)
           │              │                       ├─{gsd-usb-protect}(1309)
           │              │                       └─{gsd-usb-protect}(1348)
           │              ├─gsd-wacom(1282)─┬─{gsd-wacom}(1326)
           │              │                 └─{gsd-wacom}(1364)
           │              ├─gsd-wwan(1283)─┬─{gsd-wwan}(1300)
           │              │                ├─{gsd-wwan}(1311)
           │              │                └─{gsd-wwan}(1351)
           │              ├─gsd-xsettings(1284)─┬─{gsd-xsettings}(1333)
           │              │                     ├─{gsd-xsettings}(1345)
           │              │                     └─{gsd-xsettings}(1390)
           │              ├─gvfs-afc-volume(993)─┬─{gvfs-afc-volume}(994)
           │              │                      ├─{gvfs-afc-volume}(995)
           │              │                      └─{gvfs-afc-volume}(997)
           │              ├─gvfs-goa-volume(957)─┬─{gvfs-goa-volume}(968)
           │              │                      └─{gvfs-goa-volume}(969)
           │              ├─gvfs-gphoto2-vo(998)─┬─{gvfs-gphoto2-vo}(999)
           │              │                      └─{gvfs-gphoto2-vo}(1001)
           │              ├─gvfs-mtp-volume(983)─┬─{gvfs-mtp-volume}(984)
           │              │                      └─{gvfs-mtp-volume}(986)
           │              ├─gvfs-udisks2-vo(950)─┬─{gvfs-udisks2-vo}(951)
           │              │                      ├─{gvfs-udisks2-vo}(952)
           │              │                      └─{gvfs-udisks2-vo}(953)
           │              ├─gvfsd(935)─┬─gvfsd-trash(1382)─┬─{gvfsd-trash}(1387+
           │              │            │                   └─{gvfsd-trash}(1391+
           │              │            ├─{gvfsd}(936)
           │              │            └─{gvfsd}(937)
           │              ├─gvfsd-fuse(940)─┬─{gvfsd-fuse}(943)
           │              │                 ├─{gvfsd-fuse}(944)
           │              │                 ├─{gvfsd-fuse}(945)
           │              │                 ├─{gvfsd-fuse}(946)
           │              │                 └─{gvfsd-fuse}(949)
           │              ├─gvfsd-metadata(1991)─┬─{gvfsd-metadata}(1994)
           │              │                      └─{gvfsd-metadata}(1995)
           │              ├─ibus-portal(1203)─┬─{ibus-portal}(1204)
           │              │                   └─{ibus-portal}(1205)
           │              ├─ibus-x11(1200)─┬─{ibus-x11}(1208)
           │              │                └─{ibus-x11}(1209)
           │              ├─pulseaudio(911)─┬─{pulseaudio}(954)
           │              │                 ├─{pulseaudio}(955)
           │              │                 └─{pulseaudio}(972)
           │              ├─sh(6298)───vsls-agent(6299)─┬─{vsls-agent}(6302)
           │              │                             ├─{vsls-agent}(6309)
           │              │                             ├─{vsls-agent}(6310)
           │              │                             ├─{vsls-agent}(6311)
           │              │                             ├─{vsls-agent}(6313)
           │              │                             ├─{vsls-agent}(6314)
           │              │                             ├─{vsls-agent}(6320)
           │              │                             ├─{vsls-agent}(6321)
           │              │                             ├─{vsls-agent}(6349)
           │              │                             ├─{vsls-agent}(6460)
           │              │                             └─{vsls-agent}(6461)
           │              ├─snap-store(1440)─┬─{snap-store}(1568)
           │              │                  ├─{snap-store}(1569)
           │              │                  ├─{snap-store}(1570)
           │              │                  └─{snap-store}(1586)
           │              ├─tracker-miner-f(913)─┬─{tracker-miner-f}(930)
           │              │                      ├─{tracker-miner-f}(933)
           │              │                      ├─{tracker-miner-f}(948)
           │              │                      └─{tracker-miner-f}(1014)
           │              ├─xdg-desktop-por(1572)─┬─{xdg-desktop-por}(1573)
           │              │                       ├─{xdg-desktop-por}(1574)
           │              │                       ├─{xdg-desktop-por}(1583)
           │              │                       ├─{xdg-desktop-por}(1584)
           │              │                       └─{xdg-desktop-por}(6467)
           │              ├─xdg-desktop-por(1576)─┬─{xdg-desktop-por}(1577)
           │              │                       ├─{xdg-desktop-por}(1578)
           │              │                       └─{xdg-desktop-por}(1582)
           │              ├─xdg-document-po(1451)─┬─{xdg-document-po}(1454)
           │              │                       ├─{xdg-document-po}(1455)
           │              │                       ├─{xdg-document-po}(1459)
           │              │                       ├─{xdg-document-po}(1460)
           │              │                       ├─{xdg-document-po}(1461)
           │              │                       └─{xdg-document-po}(6463)
           │              └─xdg-permission-(1217)─┬─{xdg-permission-}(1218)
           │                                      └─{xdg-permission-}(1220)
           ├─systemd-journal(255)
           ├─systemd-logind(665)
           ├─systemd-resolve(594)
           ├─systemd-timesyn(595)───{systemd-timesyn}(610)
           ├─systemd-udevd(314)
           ├─udisksd(666)─┬─{udisksd}(689)
           │              ├─{udisksd}(731)
           │              ├─{udisksd}(789)
           │              └─{udisksd}(824)
           ├─unattended-upgr(777)───{unattended-upgr}(856)
           ├─upowerd(1003)─┬─{upowerd}(1005)
           │               └─{upowerd}(1006)
           ├─whoopsie(831)─┬─{whoopsie}(840)
           │               └─{whoopsie}(841)
           └─wpa_supplicant(667)

## Podpunkt D

./1D.x

Identyfikatory procesu macierzystego:
|ID|  UID|  GID|   PID|  PPID|  PGID|
| 0| 1000| 1000| 10419| 10411| 10411|
| 1| 1000| 1000| 10420| 10419| 10411|
| 1| 1000| 1000| 10421| 10419| 10411|
| 1| 1000| 1000| 10422| 10419| 10411|
| 2| 1000| 1000| 10424| 10420| 10411|
| 2| 1000| 1000| 10425| 10420| 10411|
| 2| 1000| 1000| 10426| 10421| 10411|
| 3| 1000| 1000| 10449| 10424| 10411|

Proces macierzysty:                             _________________PID: 10419__________________________________________
                                                |                               |                                   |
1                                           PID: 10420                          PID: 10421                          PID: 10422
                                            /         \                               \
                                           /           \                               \
                                          /             \                               \
                                         /               \                               \
                                        /                 \                               \
2                               PID: 10424          PID: 10425                          PID: 10426
                                      /
                                     /
                                    /
                                   /
3                               PID: 10449






## Podpunkt E

Przy n-krotnym użyciu funkcji fork() w pętli powstanie 2^n procesów potomnych ponieważ przy kazdym wywolaniu funkcji fork()
kazdy dzialajacy proces stworzy swój proces potomny.

> Zaktualizowano 15.03.2022