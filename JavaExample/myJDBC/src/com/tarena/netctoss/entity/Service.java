package com.tarena.netctoss.entity;

import java.sql.Date;

public class Service {
	private Long id;

	// private Integer accountId;
	// 不仅仅存放ID,还可以存放Account的其他属性
	private Account account = new Account();
	
	// private Integer costId;
	// 不仅仅存放ID,还可以存放Cost的其他属性
	private Cost cost = new Cost();

	private String unixHost;

	private String osUsername;

	private String loginPasswd;

	private String status;

	private Date createDate;

	private Date pauseDate;

	private Date closeDate;

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}

	public Integer getAccountId() {
		return account.getId();
	}

	public void setAccountId(Integer accountId) {
		account.setId(accountId);
	}

	public Integer getCostId() {
		return cost.getId();
	}

	public void setCostId(Integer costId) {
		cost.setId(costId);
	}

	public void setCostName(String costName) {
		cost.setCostName(costName);
	}

	public String getCostName() {
		return cost.getCostName();
	}

	public void setRealName(String realName) {
		account.setRealName(realName);
	}

	public String getRealName() {
		return account.getRealName();
	}

	public String getUnixHost() {
		return unixHost;
	}

	public void setUnixHost(String unixHost) {
		this.unixHost = unixHost;
	}

	public Account getAccount() {
		return account;
	}

	public void setAccount(Account account) {
		this.account = account;
	}

	public Cost getCost() {
		return cost;
	}

	public void setCost(Cost cost) {
		this.cost = cost;
	}

	public String getOsUsername() {
		return osUsername;
	}

	public void setOsUsername(String osUsername) {
		this.osUsername = osUsername;
	}

	public String getLoginPasswd() {
		return loginPasswd;
	}

	public void setLoginPasswd(String loginPasswd) {
		this.loginPasswd = loginPasswd;
	}

	public String getStatus() {
		return status;
	}

	public void setStatus(String status) {
		this.status = status;
	}

	public Date getCreateDate() {
		return createDate;
	}

	public void setCreateDate(Date createDate) {
		this.createDate = createDate;
	}

	public Date getPauseDate() {
		return pauseDate;
	}

	public void setPauseDate(Date pauseDate) {
		this.pauseDate = pauseDate;
	}

	public Date getCloseDate() {
		return closeDate;
	}

	public void setCloseDate(Date closeDate) {
		this.closeDate = closeDate;
	}

}
