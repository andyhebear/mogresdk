; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

; NEEDSREVISION: Normal installation, Windows XP Professional SP3 32-bit -> Attempt to uninstall -> "This installation can only be uninstalled on 64-bit Windows." -> ???
; SOLVED! Problem was: Invalid unins000.dat
; WORKAROUND: Delete unins000.dat, reinstall the SDK and then the uninstallation should work fine

#define MyAppName "MOGRE SDK"
#define MyAppVerName "MOGRE SDK 1.6.5 beta"
#define MyAppPublisher "Mogre Community"
#define MyAppURL "http://www.ogre3d.org/wiki/index.php/MOGRE"
; http://mogre.sourceforge.net --> redirection to MOGRE wiki

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{B155F8B3-8BCD-4687-A529-750E6F329791}
AppName={#MyAppName}
AppVerName={#MyAppVerName}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName=C:\MogreSDK
DefaultGroupName=Mogre SDK
AllowNoIcons=yes
LicenseFile=lgpl-2.1.txt
InfoBeforeFile=info_before_install.txt
InfoAfterFile=info_after_install.txt
OutputDir=output
OutputBaseFilename=MogreSDK_1.6.5_beta
SolidCompression=yes

; Compression=lzma/fast
Compression=lzma/ultra64
; lzma/ultra64 is the best compression. This would be good for download of a large SDK setup.
; But it needs more compression time, about 700MB RAM for compression and 70 MB for decompression.
; For SDK developer tests you can use lzma/fast.


WizardImageFile=InstallerWizard.bmp

[Languages]
Name: english; MessagesFile: compiler:Default.isl

[Files]
Source: ..\sdk_fs\*; DestDir: {app}; Flags: recursesubdirs createallsubdirs comparetimestamp confirmoverwrite
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: {group}\Sample browser; Filename: {app}\bin\Release\browser.exe; WorkingDir: {app}\bin\Release
Name: {group}\Browse SDK folder; Filename: {app}
Name: {group}\Build samples; Filename: {app}\BuildSamples.cmd; WorkingDir: {app}
Name: {group}\Links\MOGRE Wiki; Filename: http://www.ogre3d.org/wiki/index.php/MOGRE
Name: {group}\Links\Official MOGRE Forum; Filename: http://www.ogre3d.org/phpBB2addons/viewforum.php?f=8
Name: {group}\Report problems with Mogre SDK; Filename: http://www.ogre3d.org/addonforums/viewtopic.php?f=8&t=11703
Name: {group}\Links\Project page at Sourceforge.net; Filename: http://sourceforge.net/projects/mogre
Name: {group}\Links\Browse the sources; Filename: http://mogre.svn.sourceforge.net/viewvc/mogre/

Name: {group}\{cm:UninstallProgram,{#MyAppName}}; Filename: {uninstallexe}

Name: {app}\Sample Browser; Filename: {app}\bin\Release\browser.exe; WorkingDir: {app}\bin\Release

[Run]
Filename: {tmp}\7z.exe; Parameters: e pdb_d.7z -o{app}\bin\Debug -y; WorkingDir: {tmp}; Components: Debug_symbols; Languages: ; StatusMsg: Extracting downloaded debug symbols for debug binaries ...; Flags: runhidden
Filename: {tmp}\7z.exe; Parameters: e pdb.7z -o{app}\bin\Release -y; WorkingDir: {tmp}; Components: Debug_symbols; Languages: ; StatusMsg: Extracting downloaded debug symbols for release binaries ...; Flags: runhidden
Filename: {app}\dependencycheck.exe; WorkingDir: {app}; StatusMsg: Checking for required dependencies ...; Languages: 
Filename: {win}\Microsoft.NET\Framework\v2.0.50727\ngen.exe; Parameters: "install ""{app}\bin\Release\browser.exe"""; WorkingDir: {app}; StatusMsg: Optimizing performance for your system ...; Flags: runhidden
Filename: {win}\Microsoft.NET\Framework\v2.0.50727\ngen.exe; Parameters: "install ""{app}\bin\Release\Mogre.dll"""; WorkingDir: {app}; StatusMsg: Optimizing performance for your system ...; Flags: runhidden

[Components]
Name: Debug_symbols; Description: Debug symbols for Mogre.dll and OgreMain.dll; ExtraDiskSpaceRequired: 272945152; Types: custom

[_ISToolDownload]
Source: http://mogresdk.googlecode.com/svn/trunk/sdk_fs_optional/bin/Release/pdb.7z; DestDir: {tmp}; DestName: pdb.7z; Components: Debug_symbols
Source: http://mogresdk.googlecode.com/svn/trunk/sdk_fs_optional/bin/Debug/pdb_d.7z; DestDir: {tmp}; DestName: pdb_d.7z; Components: Debug_symbols
Source: http://mogresdk.googlecode.com/svn/trunk/installer/tmp/7z.exe; DestDir: {tmp}; DestName: 7z.exe; Components: Debug_symbols
Source: http://mogresdk.googlecode.com/svn/trunk/installer/tmp/7z.dll; DestDir: {tmp}; DestName: 7z.dll; Components: Debug_symbols
[Code]
// Function generated by ISTool.
function NextButtonClick(CurPage: Integer): Boolean;
begin
	Result := istool_download(CurPage);
end;
