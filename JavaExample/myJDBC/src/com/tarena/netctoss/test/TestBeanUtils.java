package com.tarena.netctoss.test;

import org.apache.commons.beanutils.BeanUtils;

import com.tarena.netctoss.entity.Account;

public class TestBeanUtils {
	public static void main(String[] args) throws Exception {
		Account account = new Account();
		// account.setId(1000);

		// BeanUtils.setProperty(obj, name, value)
		// obj 给哪个对象设置属性
		// name 要设置的属性名
		// value 要设置的属性值
		BeanUtils.setProperty(account, "id", 10000);
		BeanUtils.setProperty(account, "loginName", null);
		// 在设置日期类型属性的时候,其值不能为null
		BeanUtils.setProperty(account, "createDate", null);

		System.out.println(account.getId() + "," + account.getLoginName() + ","
				+ account.getCreateDate());

	}
}
