#include<iostream>
#include<cstdlib>
#include<conio.h>


using namespace std;



main()

{
	

	cout<<"[1] Wi-Fi Password Recovery (Cmd Method)"<<"\n[2] Wi-Fi Password Recovery (PowerShell Method)"<<"\n[3] Show This Pc Interface info"<<"\n[4] Show Details Of Nearby Networks"<<"\n[5] About This App";
	cout<<"\n\nEnter A Number: ";
	int en;
	cin>>en;


	if (en==1) 
	
	{

		string nwl,iface;


		system("Netsh Wlan Show Profiles");

		cout<<"\n\nType Access Point Name: ";
		
		
		char accc[35];
		cin.getline(accc,35);
		string acc=accc;
		
		
		

			cout<<"\n\nEnter Interface Name (Enter 0 For Skip): ";
			
			


			cin>>iface;
			
			

		    if(iface=="0")
		    
	     	 {

	    	nwl="Netsh Wlan Show Profiles " + acc + " | find /I \"SSID name\" && " + "Netsh Wlan Show Profiles " + acc + " | find /I \"Authentication\" && " + "Netsh Wlan Show Profiles " + acc + " Key=Clear | find /I \"Key Content\"";

		     const char *command = nwl.c_str();

	     	system(command);

             

          	}


		


              else if (iface!="0")
              
		       {
		       	
		       string nwl2;	
			   
			   nwl2="Netsh Wlan Show Profiles " + acc + " interface=" + iface + " | find /I \"SSID name\" && " + "Netsh Wlan Show Profiles " + acc + " interface=" + iface + " | find /I \"Authentication\" && " + "Netsh Wlan Show Profiles " + acc + " interface=" + iface + " Key=Clear | find /I \"Key Content\"";
		       	
		       	const char *commandd = nwl2.c_str();

	            	system(commandd);




		           }
		




		  }




              else if(en==2)
			  {
			  	
			  	system("powershell.exe \"(netsh wlan show profiles) | Select-String \"\\\"\\:(.+)$\"\\\" | %{$name=$_.Matches.Groups[1].Value.Trim(); $_} | %{(netsh wlan show profile name=\"$name\" key=clear)}  | Select-String \"\\\"Key Content\\W+\\:(.+)$\"\\\" | %{$pass=$_.Matches.Groups[1].Value.Trim(); $_} | %{(netsh wlan show profile name=\"$name\" key=clear)}  | Select-String \"\\\"Authentication\\W+\\:(.+)$\"\\\" | %{$Auth=$_.Matches.Groups[1].Value.Trim(); $_} | %{[PSCustomObject]@{ SSID_name=$name;Authentication=$Auth;Password=$pass }} | Format-Table -AutoSize\"");
			  	
				   }     



         else if (en==3)
         
        {
        	system("Netsh Wlan Show interface");
         	
         
	  	 }
	  	 
	  	 
	  	 
	  	 else if (en==4)

		 {
		 	system("Netsh Wlan Show Networks Mode=Bssid");
		 }



	




	 else if (en==5)

	{
		
		cout<<"\n\asoftware name: Simple Wi-Fi Password(Key) Recovery Program";
		cout<<"\nRelease year: 2022";
		cout<<"\nPlatform: Windows (Console)";
		cout<<"\nlanguage: C++";
		cout<<"\ndeftincomputer.blogspot.com";
		cout<<"\nEmail: deftincomputer@gmail.com";
		
	}


    else

    {
    	cout<<"\n\aInput Error!!!";
    }




	getch();

}


