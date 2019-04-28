package com.tarena.netctoss.test;


public class Foo {
	// private static Foo foo = new Foo();
//	private static Map<Thread, Foo> map = 
//		  new HashMap<Thread, Foo>();
	// ��һ���Ե�ǰ�߳�ΪKEY��Ŷ��������(Map)
	private static ThreadLocal<Foo> tl = 
		  new ThreadLocal<Foo>();

	public static synchronized Foo getInstance() {
		// ��ȡ��ǰ�߳�
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
