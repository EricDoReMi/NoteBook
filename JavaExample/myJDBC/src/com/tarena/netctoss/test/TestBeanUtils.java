package com.tarena.netctoss.test;

import org.apache.commons.beanutils.BeanUtils;

import com.tarena.netctoss.entity.Account;

public class TestBeanUtils {
	public static void main(String[] args) throws Exception {
		Account account = new Account();
		// account.setId(1000);

		// BeanUtils.setProperty(obj, name, value)
		// obj ���ĸ�������������
		// name Ҫ���õ�������
		// value Ҫ���õ�����ֵ
		BeanUtils.setProperty(account, "id", 10000);
		BeanUtils.setProperty(account, "loginName", null);
		// �����������������Ե�ʱ��,��ֵ����Ϊnull
		BeanUtils.setProperty(account, "createDate", null);

		System.out.println(account.getId() + "," + account.getLoginName() + ","
				+ account.getCreateDate());

	}
}
