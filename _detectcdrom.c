�B�J�@:���o���о��N��
�ϥΨ禡:
UINT GetDriveType(
LPCTSTR lpRootPathName // pointer to root path
);
�Y�^�ǭȬ�DRIVE_CDROM,�h�N���˸m�O���о� 

�B�J�G:�T�{���Ф��e�Υ��м���(label),�H�קK����x�H�W���о��ɧ�����ХN�� 

�d��:


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
    // ��d:�Ϻж}�l�ˬd��z:�Ϻ�
    for (i='D'; i<='Z'; i++)
    {
      drive_name[0]=i;
      if(GetDriveType(drive_name)==DRIVE_CDROM)
      {   
        //�o�̤]�i�令�T�{�ɮפ��e,�N���w���ɮ�fopen���\
        //�Y�N����ЬO���T��
        
        //���o���м��ҦW��
        GetVolumeInformation(drive_name, VolumeName, 
        strlen(VolumeName), NULL, NULL, NULL, NULL, NULL);
        CDRom_Exist=TRUE;
        //�P�_�O�_�����w�����ҦW��
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
        //�䤣����Ҭ�"disk1"�����Ф�!
        CDRom_Exist = FALSE;
      }
      else
      }	
        //�䤣����о��˸m
        break;
      }
    }
  }while(CDRom_Exist==FALSE); 