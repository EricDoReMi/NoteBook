package com.tarena.netctoss.test;
/**
 * Ïàµ±ÓÚservice²ã
 */

import java.sql.Connection;
import java.util.List;

import org.junit.Test;

import com.tarena.netctoss.dao.AccountDAO;
import com.tarena.netctoss.entity.Account;

public class AccountDAOTest {
	@Test
	public void testFindAll() throws Exception {
		AccountDAO accountDAO = new AccountDAO();
		Connection con = accountDAO.begin();
		try {
			List<Account> accountList = accountDAO.findAll(con,2, 3);
			for (Account account : accountList) {
				System.out.println(account);
			}
		} catch (Exception e) {
			accountDAO.rollback();
			e.printStackTrace();
		}finally{
			accountDAO.close();
		}
		
	}

	@Test
	public void testGetTotalPages() throws Exception {
		AccountDAO accountDAO = new AccountDAO();
		Connection con = accountDAO.begin();
		try {
			int totalPages = accountDAO.getTotalPages(con,3);
			System.out.println(totalPages);
		} catch (Exception e) {
			accountDAO.rollback();
			e.printStackTrace();
		}finally{
			accountDAO.close();
		}
	}

	@Test
	public void testFindBy() throws Exception {
	}
}
