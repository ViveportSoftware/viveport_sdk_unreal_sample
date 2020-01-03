# VIVEPORT SDK Unreal Sample

## For DRM wrapper Error, other use this VIVEPORT SDK DRM solution.

* Download DRM_fix_Component.
* Copy ViveportSDK to your Unreal project .\Plugins folder.
* Change .\Plugins\ViveportSDK\Source\ViveportSDK\Classes\ViveportDRMComponent.h to your VIVEPORT ID and VIVEPORT KEY.
* Remove .\Plugins\ViveportSDK\Binaries , .\Plugins\ViveportSDK\Intermediate , your Project's .\Binaries and your Project's .\Intermediate folder.
* Start your .uproject. ureanl will start rebuild your project.
* Create new Actor in your map and add Viveport DRM component . 
* Run your project. If your viveport account doesn't have this app, Unral editor will end. This VIVEPORT SDK DRM is work.