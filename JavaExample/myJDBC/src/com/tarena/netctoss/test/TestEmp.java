package com.tarena.netctoss.test;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import com.tarena.netctoss.utils.DBUtils;

public class TestEmp {
	public static void main(String[] args) throws Exception {

		Connection con = DBUtils.getConnection();

		PreparedStatement stmt = con.prepareStatement("select * from emp "
				+ "where (1=? or ename=?) and (1=? or job=?)");

		stmt.setInt(1, 0);
		stmt.setString(2, "ABC");
		stmt.setInt(3, 0);
		stmt.setString(4, "CLERK");

		ResultSet rs = stmt.executeQuery();
		while (rs.next()) {
			System.out.println(rs.getString(1) + "," + rs.getString(2) + ","
					+ rs.getString(3));
		}

		con.close();
	}
}
