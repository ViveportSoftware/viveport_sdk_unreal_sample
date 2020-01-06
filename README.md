# VIVEPORT SDK Unreal Sample


## DRM_fix_Component Sample 
### Description
 If you encountered with VIVEPORT DRM wrapper compatibility issue in your unreal content, you can follow this sample to enable VIVEPORT DRM SDK.

### Tutorial 
* Download ViveportSDK Unreal. https://developer.viveport.com/documents/sdk/en/unrealengine.html
* Download DRM_fix_Component.
* Copy DRM_fix_Component\ViveportSDK folder to your Unreal project .\Plugins folder.
* Change .\Plugins\ViveportSDK\Source\ViveportSDK\Classes\ViveportDRMComponent.h to your VIVEPORT ID and VIVEPORT KEY.
* If .\Plugins\ViveportSDK\Binaries and .\Plugins\ViveportSDK\Intermediate, exist , please remove them. Then remove your Project's .\Binaries and your Project's .\Intermediate folder.
* Start your .uproject. Unreal will start rebuild your project.
* Create a new Actor in your map and add Viveport DRM component . 
* Run your project. If your VIVEPORT account doesn't own this app, Unreal editor will close. It means VIVEPORT DRM SDK is workable now.