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
	 * 根据accountId查询与之关联的Service数据
	 * 返回的Service数据中需要包含Account的LOGIN_NAME
	 * 和Cost的COST_Name
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
