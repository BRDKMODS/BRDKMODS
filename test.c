class BarDuckAlarmpostObject {
    string postclassname;	
    ref array<string> suondslist;
	float TriggerRadius;
    float TriggerCooldonw; 
}

class BarDuckAlarmpostConfig
{
   const static string cfgPathWay = "$profile:BRDK_MODS/BarDuckAlarmpost.json";
   const static string dirPathName = "$profile:\\BRDK_MODS";
 
   ref array<ref BarDuckAlarmpostObject> BarDuckAlarmpostObjects = new array<ref BarDuckAlarmpostObject>; 


    void BarDuckAlarmpostConfig()
    {
		Print("[BarDuckAlarmpostConfig] config found, loading...");
        LoadBarDuckAlarmpostCFG();
    }

    private void LoadBarDuckAlarmpostCFG()
    {
        if (FileExist(cfgPathWay))
		{
			JsonFileLoader<BarDuckAlarmpostConfig>.JsonLoadFile(cfgPathWay, this);
		}
        else
		{
			CreateBarDuckAlarmpostConfig();
		}
    }	

    private void SaveBarDuckAlarmpostCFG()
    {
        JsonFileLoader<BarDuckAlarmpostConfig>.JsonSaveFile( cfgPathWay, this );
    }

    private void CreateBarDuckAlarmpostConfig()
    {
        if (!FileExist(dirPathName))
        {
            Print("[BarDuckAlarmpostConfig] '" + dirPathName + "' does not exist, creating...");
            MakeDirectory(dirPathName);
        }

		
		BarDuckAlarmpostObject new_BarDuckAlarmpostObject = new BarDuckAlarmpostObject;
		new_BarDuckAlarmpostObject.postclassname = "RadioPost";
		new_BarDuckAlarmpostObject.suondslist = {"RadioPost_SoundSet", "ChemPost_SoundSet"};
		new_BarDuckAlarmpostObject.TriggerRadius = 10;		
		new_BarDuckAlarmpostObject.TriggerCooldonw = 60;					

		BarDuckAlarmpostObjects.Insert(new_BarDuckAlarmpostObject);
		
        SaveBarDuckAlarmpostCFG();
	}		
}

static ref BarDuckAlarmpostConfig g_BarDuckAlarmpostConfig = new BarDuckAlarmpostConfig();
static ref BarDuckAlarmpostConfig GetBarDuckAlarmpostConfig()
{
    if(!g_BarDuckAlarmpostConfig) g_BarDuckAlarmpostConfig = new BarDuckAlarmpostConfig();
    return g_BarDuckAlarmpostConfig;
}

