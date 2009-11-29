; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "MOGRE SDK"
#define MyAppVerName "MOGRE SDK 1.6.4 Beta"
#define MyAppPublisher "Mogre Community"
#define MyAppURL "http://mogre.sourceforge.net/"

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
OutputDir=output
OutputBaseFilename=MogreSDK_1.6.4_beta
Compression=lzma
SolidCompression=yes

WizardImageFile=InstallerWizard.bmp

[Languages]
Name: english; MessagesFile: compiler:Default.isl

[Files]
Source: ..\sdk_fs\*; DestDir: {app}; Flags: ignoreversion recursesubdirs createallsubdirs
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: {group}\Browse SDK folder; Filename: {app}
Name: {group}\Build samples; Filename: {app}\BuildSamples.cmd; WorkingDir: {app}
Name: {group}\Links\MOGRE Website; Filename: {#MyAppURL}
Name: {group}\Links\Official MOGRE Forum; Filename: http://www.ogre3d.org/phpBB2addons/viewforum.php?f=8
Name: {group}\Links\Project page at Sourceforge.net; Filename: http://sourceforge.net/projects/mogre
Name: {group}\Links\Browse the sources; Filename: http://mogre.svn.sourceforge.net/viewvc/mogre/

Name: {group}\{cm:UninstallProgram,{#MyAppName}}; Filename: {uninstallexe}
