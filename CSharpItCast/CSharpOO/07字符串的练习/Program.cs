using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _07字符串的练习
{
    class Program
    {
        static void Main(string[] args)
        {
            //课上练习1：接收用户输入的字符串，将其中的字符以与输入相反的顺序输出。"abc"→"cba"

            //string str = "abcdefg";//ggedcba
            //char[] chs = str.ToCharArray();
            //for (int i = 0; i < chs.Length / 2; i++)
            //{
            //    char temp = chs[i];
            //    chs[i] = chs[chs.Length - 1 - i];
            //    chs[chs.Length - 1 - i] = temp;
            //}

            //str = new string(chs);
            //Console.WriteLine(str);
            //Console.ReadKey();


            //倒叙循环
            //for (int i = str.Length - 1; i >= 0; i--)
            //{
            //    Console.Write(str[i]);
            //}

            //"hello c sharp"→"sharp c hello"
            //string str = "hello c sharp";
            //string[] strNew = str.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            //for (int i = 0; i < strNew.Length / 2; i++)
            //{
            //    string temp = strNew[i];
            //    strNew[i] = strNew[strNew.Length - 1 - i];
            //    strNew[strNew.Length - 1 - i] = temp;
            //}

            //str = string.Join(" ", strNew);
            //Console.WriteLine(str);
            //string.join:将字符串按照指定的分隔符连接
            //Console.WriteLine(strNew);//sharp c hello
            // sharp c hello

            //for (int i = 0; i < strNew.Length; i++)
            //{
            //    Console.WriteLine(strNew[i]);
            //}


            //课上练习3：从Email中提取出用户名和域名：abc@163.com。
            //string email = "285014478@qq.com";
            //int index = email.IndexOf('@');
            //string userName = email.Substring(0, index);
            //string yuMing = email.Substring(index+1);
            //Console.WriteLine(yuMing);
            //Console.WriteLine(userName);


            //Console.ReadKey();



            //课上练习4：文本文件中存储了多个文章标题、作者，
            //标题和作者之间用若干空格（数量不定）隔开，每行一个，
            //标题有的长有的短，输出到控制台的时候最多标题长度10，
            //如果超过10，则截取长度8的子串并且最后添加“...”，加一个竖线后输出作者的名字。


            //string path = @"C:\Users\SpringRain\Desktop\1.txt";
            //string[] contents = File.ReadAllLines(path, Encoding.Default);
            //for (int i = 0; i < contents.Length; i++)
            //{
            //    string[] strNew = contents[i].Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            //    Console.WriteLine((strNew[0].Length>10?strNew[0].Substring(0,8)+"......":strNew[0])+"|"+strNew[1]);
            //}
            //Console.ReadKey();




            //历史就是这么回事儿|袁腾飞
            //c#基础之循环结构while、do-while|老赵
            //AV|苍老师
            //坏蛋是怎样炼成的怎样炼成的|六道


            //让用户输入一句话,找出所有e的位置
            //string str = "咳嗽、咳嗽 哈哈咳嗽 咳 咳  咳嗽";
            //for (int i = 0; i < str.Length; i++)
            //{
            //    if (str[i] == 'e')
            //    {
            //        Console.WriteLine(i);
            //    }
            //}
            //Console.ReadKey();


            //int index = str.IndexOf('e');
            //Console.WriteLine("第1次出现e的位置是{0}", index);
            ////循环体：从上一次出现e的位置加1的位置找下一次e出现的位置
            ////循环条件：index!=-1
            //int count = 1;//用来记录e出现的次数
            //while (index != -1)
            //{
            //    count++;
            //    index = str.IndexOf('e', index + 1);
            //    if (index == -1)
            //    {
            //        break;
            //    }
            //    Console.WriteLine("第{0}次出现e的位置是{1}",count,index);
            //}
            //Console.ReadKey();



            //用户输入一句话,判断这句话中有没有邪恶,如果有邪恶就替换成这种形式然后输出,如:老牛很邪恶,输出后变成老牛很**;
            //string str = "老牛很邪恶";
            //if (str.Contains("邪恶"))
            //{
            //    str = str.Replace("邪恶", "**");
            //}
            //Console.WriteLine(str);
            //Console.ReadKey();

            //把{“诸葛亮”,”鸟叔”,”卡卡西”,”卡哇伊”}变成诸葛亮|鸟叔|卡卡西|卡哇伊,然后再把|切割掉
            string[] names = { "诸葛亮", "鸟叔", "卡卡西", "卡哇伊" };
            string str = string.Join("|", names);
            string[] strNew = str.Split(new char[] { '|' }, StringSplitOptions.RemoveEmptyEntries);
            //  Console.WriteLine(str);
            Console.ReadKey();
        }
    }
}
