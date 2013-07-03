步驟一:取得光碟機代號
使用函式:
UINT GetDriveType(
LPCTSTR lpRootPathName // pointer to root path
);
若回傳值為DRIVE_CDROM,則代表此裝置是光碟機 

步驟二:確認光碟內容或光碟標籤(label),以避免當有兩台以上光碟機時抓錯光碟代號 

範例:


  int   i;
  int   CDRom_Exist;
  char  drive_name[8];
  char  LabelName[128],VolumeName[128];
  
  drive_name[1]=':';
  drive_name[2]='\\0';
  strcpy(LabelName,"disk1");
  CDRom_Exist = FALSE;
  
  do
  {
    // 由d:磁碟開始檢查到z:磁碟
    for (i='D'; i<='Z'; i++)
    {
      drive_name[0]=i;
      if(GetDriveType(drive_name)==DRIVE_CDROM)
      {   
        //這裡也可改成確認檔案內容,將指定的檔案fopen成功
        //即代表光碟是正確的
        
        //取得光碟標籤名稱
        GetVolumeInformation(drive_name, VolumeName, 
        strlen(VolumeName), NULL, NULL, NULL, NULL, NULL);
        CDRom_Exist=TRUE;
        //判斷是否為指定的標籤名稱
        if(strcmp(LabelName, VolumeName)==0)
        {
          break; 
        }
      }
    }
    if(i>'Z')
    {
      if(CDRom_Exist)
      {
        //找不到標籤為"disk1"的光碟片!
        CDRom_Exist = FALSE;
      }
      else
      }	
        //找不到光碟機裝置
        break;
      }
    }
  }while(CDRom_Exist==FALSE); 