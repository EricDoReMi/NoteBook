package com.tarena.netctoss.dao;

import java.math.BigDecimal;
import java.sql.Connection;
import java.sql.ResultSet;
import java.util.List;

import org.apache.commons.lang3.ArrayUtils;

import com.tarena.netctoss.entity.Account;
import com.tarena.netctoss.utils.EntityUtils;

public class AccountDAO extends BaseDAO<Account> {

	/**
	 * 
	 * @param account
	 * @throws Exception
	 */
	public void save(Connection con,Account account) throws Exception {
		update(con,ACCOUNT_SAVE, account.toArray());
	}

	/**
	 * 
	 * @param page
	 * @param rowsPerPage
	 * @return
	 * @throws Exception
	 */
	public List<Account> findAll(Connection con,int page, int rowsPerPage) throws Exception {
		int min = (page - 1) * rowsPerPage + 1;
		int max = min + rowsPerPage;
		return queryEntity(con,ACCOUNT_FIND_ALL, new Object[] { max, min });
	}

	/**
	 * 
	 * @param rowsPerPage
	 * @return
	 * @throws Exception
	 */
	public int getTotalPages(Connection con,int rowsPerPage) throws Exception {
		List list = query(con,ACCOUNT_GET_TOTAL_ROWS, null);
		int totalRows = ((BigDecimal) list.get(0)).intValue();
		if (totalRows % rowsPerPage == 0) {
			return totalRows / rowsPerPage;
		} else {
			return totalRows / rowsPerPage + 1;
		}
	}

	/**
	 * 
	 * @param id
	 * @return
	 * @throws Exception
	 */
	public Account findByID(Connection con,int id) throws Exception {
		List<Account> list = queryEntity(con,ACCOUNT_FIND_BY_ID,
				new Object[] { id });
		if (list.size() > 0) {
			return list.get(0);
		} else {
			return null;
		}
	}

	/**
	 * 
	 * @param page
	 * @param rowsPerPage
	 * @param account
	 * @return
	 * @throws Exception
	 */
	public List<Account> findBy(Connection con,int page, int rowsPerPage, Account account)
			throws Exception {
		Object[] params = new Object[10];
		int min = (page - 1) * rowsPerPage + 1;
		int max = min + rowsPerPage;
		int i = 0;
		if (account.getIdcard() != null) {
			params[i++] = 1;
			params[i++] = "%" + account.getIdcard() + "%";
		} else {
			params[i++] = 0;
			params[i++] = " ";
		}
		if (account.getRealName() != null) {
			params[i++] = 1;
			params[i++] = "%" + account.getRealName() + "%";
		} else {
			params[i++] = 0;
			params[i++] = " ";
		}
		if (account.getLoginName() != null) {
			params[i++] = 1;
			params[i++] = "%" + account.getLoginName() + "%";
		} else {
			params[i++] = 0;
			params[i++] = " ";
		}
		if (account.getStatus() != null) {
			params[i++] = 1;
			params[i++] = account.getStatus();
		} else {
			params[i++] = 0;
			params[i++] = " ";
		}
		params[i++] = max;
		params[i] = min;
		return queryEntity(con,ACCOUNT_FIND_BY, params);
	}

	/**
	 * 
	 * @param account
	 * @throws Exception
	 */
	public void update(Connection con,Account account) throws Exception {
		Object[] params = account.toArray();
		params = ArrayUtils.add(params, account.getId());
		update(con,ACCOUNT_UPDATE, params);
	}

	/**
	 * 
	 * @param id
	 * @param status
	 * @throws Exception
	 */
	public void updateState(Connection con,Integer id, int status) throws Exception {
		update(con,ACCOUNT_UPDATE_STATUS, new Object[]{status,id});
	}

	@Override
	public Account toEntity(ResultSet rs) throws Exception {
		Account account = new Account();
		// 调用fillEntity方法填充Account
		EntityUtils.fillEntity(rs, account);
		return account;
	}

}
