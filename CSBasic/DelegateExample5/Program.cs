using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DelegateExample3
{
    class Program
    {
        static void Main(string[] args)
        {
            //模板方法了
            ProductFactory productFactory = new ProductFactory();
            WrapFactory wrapFactory = new WrapFactory();

            Func<Product> func1 = new Func<Product>(productFactory.MakePizza);
            Func<Product> func2 = new Func<Product>(productFactory.MakeToyCar);

            //回调的方法
            Logger logger = new Logger();
            Action<Product> log = new Action<Product>(logger.Log);


            Box b1 = wrapFactory.WrapProduct(func1,log);
            Box b2 = wrapFactory.WrapProduct(func2,log);

            Console.WriteLine(b1.Product.Name);
            Console.WriteLine(b2.Product.Name);

        }
    }

    class Logger
    {
        public void Log(Product product)
        {
            Console.WriteLine("Product '{0}' created at {1},Price is {2} . ",product.Name,DateTime.UtcNow,product.Price);
        }
    }

    class Product
    {
        public string Name { get; set; }
        public double Price { get; set; }
    }

    class Box
    {
        public Product Product { get; set; }
    }

    class WrapFactory
    {
        public Box WrapProduct(Func<Product> getProduct,Action<Product> logCallback)
        {
            Box box = new Box();
            Product product = getProduct.Invoke();
            if (product.Price >= 50) {
                logCallback(product);
            }
            box.Product = product;
            return box;
        }
    }

    class ProductFactory
    {
        public Product MakePizza()
        {
            Product product = new Product();
            product.Name = "Pizza";
            product.Price = 105;
            return product;
        }

        public Product MakeToyCar()
        {
            Product product = new Product();
            product.Name = "ToyCar";
            product.Price = 2;
            return product;
        }
    }
}
