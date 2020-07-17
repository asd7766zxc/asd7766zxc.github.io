using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace WebBrowserRequest
{
    class Program
    {
        public static string Target = "http://www.mksh.phc.edu.tw/Anonymous/NewsDetail.aspx?NID=19105";
        static void Main(string[] args)
        {

            string externalip = new WebClient().DownloadString("http://icanhazip.com");
            Console.WriteLine(externalip);
            for (int r = 0; r < 10; r++)
            {
                Task.Run(() =>
                {
                    for (int i = 0; i < int.MaxValue; i++)
                    {
                        Console.WriteLine(DateTime.Now+" "+isAlive(Target));
                    }
                });
            }
  
            HttpWebRequest.Create(Target).GetResponseAsync();
            Console.ReadLine();
        }

        public static string isAlive(string url)
        {

            WebRequest request = WebRequest.Create(url);
            try
            {
                using (HttpWebResponse response = (HttpWebResponse)request.GetResponse())
                {
                    return Convert.ToString((int)response.StatusCode);
                }

            }
            catch (WebException ex)
            {
                using (HttpWebResponse res = (HttpWebResponse)ex.Response)
                {
                    return Convert.ToString((int)res.StatusCode);
                }
            }
        }
     
    }
}
