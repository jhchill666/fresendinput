#
echo Starting build of SendInputLib.swc - `date`

cp ../../FRESendInput/Debug/FRESendInput.dll .
/Applications/Adobe\ Flash\ Builder\ 4.5/sdks/flex_sdk_4.5.1.21328_air3/bin/adt -package -storetype pkcs12 -keystore sendInput.p12 -storepass test -tsa none -target ane SendInputLib.ane extension.xml -swc SendInputLib.swc -platform Windows-x86 library.swf FRESendInput.dll