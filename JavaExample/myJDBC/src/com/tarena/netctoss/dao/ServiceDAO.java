package com.tarena.netctoss.dao;

import java.sql.Connection;
import java.sql.ResultSet;
import java.util.List;

import com.tarena.netctoss.entity.Service;
import com.tarena.netctoss.utils.EntityUtils;

public class ServiceDAO extends BaseDAO<Service> {
	
	//TODO
	public void save(Connection con,Service service) {
		
	}
	
	/**
	 * ����accountId��ѯ��֮������Service����
	 * ���ص�Service��������Ҫ����Account��LOGIN_NAME
	 * ��Cost��COST_Name
	 * 
	 * select * from Service where account_id=?
	 * 
	 * @param accountId
	 * @return
	 * @throws Exception
	 */
	public List<Service> findByAccountID (Connection con,int accountId) throws Exception {
		return queryEntity(con,SERVICE_FIND_BY_ACCOUNT_ID, new Object[]{accountId});
	}

	@Override
	public Service toEntity(ResultSet rs) throws Exception {
		Service service = new Service();
		EntityUtils.fillEntity(rs, service);
		return service;
	}

}
