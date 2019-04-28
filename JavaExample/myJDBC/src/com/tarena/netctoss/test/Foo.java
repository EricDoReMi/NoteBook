package com.tarena.netctoss.test;


public class Foo {
	// private static Foo foo = new Foo();
//	private static Map<Thread, Foo> map = 
//		  new HashMap<Thread, Foo>();
	// 是一个以当前线程为KEY存放对象的容器(Map)
	private static ThreadLocal<Foo> tl = 
		  new ThreadLocal<Foo>();

	public static synchronized Foo getInstance() {
		// 获取当前线程
		// Thread t = Thread.currentThread();
		Foo foo = tl.get();
		if (foo == null) {
			foo = new Foo();
			tl.set(foo);
		}
		return foo;
	}

	//
	private Foo() {
	}

}
