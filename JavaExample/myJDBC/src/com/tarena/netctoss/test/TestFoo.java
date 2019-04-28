package com.tarena.netctoss.test;

public class TestFoo {
	public static void main(String[] args) {
		Foo foo1 = Foo.getInstance();
		Foo foo2 = Foo.getInstance();
		System.out.println("1: " + foo1);
		System.out.println("2: " + foo2);
		System.out.println(foo1 == foo2);

		Thread t = new Thread() {
			@Override
			public void run() {
				Foo foo3 = Foo.getInstance();
				Foo foo4 = Foo.getInstance();
				System.out.println("3: " + foo3);
				System.out.println("4: " + foo4);
			}
		};
		t.start();
	}
}
