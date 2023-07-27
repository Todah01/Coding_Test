#if 0
#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int painting = section[0] - 1;

    for (int idx : section) {
        if (painting < idx) {
            painting = min(idx + m - 1, n);
            answer++;
        }
    }

    return answer;
}
#endif

#if 0
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Globalization;
using Excel = Microsoft.Office.Interop.Excel;
using Microsoft.Scripting;
using Microsoft.Scripting.Hosting;
using IronPython.Hosting;
using static System.Console;

namespace Hello
{
    class MainApp
    {
        static void Main(string[] args)
        {
            ScriptEngine engine = Python.CreateEngine();
            ScriptScope scope = engine.CreateScope();
            scope.SetVariable("n", "±èµ¿Çö");
            scope.SetVariable("p", "010-0000-0000");

            ScriptSource source = engine.CreateScriptSourceFromString(@"
                class NameCard :
                name = ''
                phone = ''

                def __init__(self, name, phone) :
                self.name = name
                self.phone = phone

                def printNameCard(self) :
                print self.name + ', ' + self.phone

                NameCard(n, p)");

                dynamic result = source.Execute(scope);
            result.printNameCard();

            WriteLine("{0}, {1}", result.name, result.phone);
        }
        //public static void OldWay(string[,] data, string savePath)
        //{
        //    Excel.Application excelApp = new Excel.Application();
        //    excelApp.Workbooks.Add(Type.Missing);

        //    Excel.Worksheet workSheet = (Excel.Worksheet)excelApp.Application;

        //    for (int i = 0; i < data.GetLength(0); i++)
        //    {
        //        ((Excel.Range)workSheet.Cells[i + 1, 1]).Value2 = data[i, 0];
        //        ((Excel.Range)workSheet.Cells[i + 1, 1]).Value2 = data[i, 0];
        //    }

        //    workSheet.SaveAs(savePath + "\\shpark-book.old.xlsx",
        //        Type.Missing,
        //        Type.Missing,
        //        Type.Missing,
        //        Type.Missing,
        //        Type.Missing,
        //        Type.Missing,
        //        Type.Missing,
        //        Type.Missing);

        //    excelApp.Quit();
        //}

        //public static void NewWay(string[,] data, string savePath)
        //{
        //    Excel.Application excelApp = new Excel.Application();
        //    excelApp.Workbooks.Add();

        //    Excel._Worksheet workSheet = (Excel._Worksheet)excelApp.ActiveSheet;

        //    for(int i = 0; i < data.GetLength(0); i++)
        //    {
        //        workSheet.Cells[i + 1, 1] = data[i, 0];
        //        workSheet.Cells[i + 1, 2] = data[i, 1];
        //    }

        //    workSheet.SaveAs(savePath + "\\shpark--book-dynamic.xlsx");
        //    excelApp.Quit();
        //}

        //static void Main(string[] args)
        //{
        //    string savePath = System.IO.Directory.GetCurrentDirectory();
        //    string[,] array = new string[,]
        //    {
        //        {"ºû¼Ó¼º ¿õ¹¦¹«»ç", "Ãµ¶û"},
        //        {"¾Ï¼Ó¼º ¿¡ÀÌÀüÆ®", "½Çºñ¾Æ"},
        //        {"¾Ï¼Ó¼º ¸¶µµ»ç", "Å°Å°"},
        //        {"ºÒ¼Ó¼º ½Å¼ö½Â", "Äí¸¶¸£"},
        //        {"Ç³¼Ó¼º ½Å¼ö½Â", "¸®Å×½¬"},
        //        {"¹°¼Ó¼º ÀÎµå¶ó", "ÆÄ¸£ÀÜ¾ß"},
        //        {"Ç³¼Ó¼º ³úÁ¦", "¿Àµò"}
        //    };

        //    WriteLine("Creating Excel document in old way...");
        //    OldWay(array, savePath);

        //    WriteLine("Creating Excel document in new way...");
        //    NewWay(array, savePath);
        //}
    }
}
#endif