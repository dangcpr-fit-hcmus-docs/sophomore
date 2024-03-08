--Tao CSDL--
drop database [QLKhachSan]
create database [QLKhachSan]
GO
USE [QLKhachSan]
GO
/****** Object:  Table [dbo].[DATPHONG]    Script Date: 23/05/2022 14:59:53 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[DATPHONG](
	[MaDatPhong] [int] NOT NULL,
	[MaKH] [char](5) NULL,
	[MaPhong] [char](5) NULL,
	[NgayDat] [datetime] NULL,
	[NgayTra] [datetime] NULL,
	[ThanhTien] [float] NULL,
 CONSTRAINT [PK_DATPHONG] PRIMARY KEY CLUSTERED 
(
	[MaDatPhong] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[KHACH]    Script Date: 23/05/2022 14:59:53 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[KHACH](
	[MaKH] [char](5) NOT NULL,
	[HoTen] [nvarchar](50) NULL,
	[DiaChi] [nvarchar](100) NULL,
	[DienThoai] [char](10) NULL,
 CONSTRAINT [PK_KHACH] PRIMARY KEY CLUSTERED 
(
	[MaKH] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[PHONG]    Script Date: 23/05/2022 14:59:53 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[PHONG](
	[MaPhong] [char](5) NOT NULL,
	[TinhTrang] [nvarchar](50) NULL,
	[LoaiPhong] [nvarchar](50) NULL,
	[DonGia] [float] NULL,
 CONSTRAINT [PK_PHONG] PRIMARY KEY CLUSTERED 
(
	[MaPhong] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
INSERT [dbo].[KHACH] ([MaKH], [HoTen], [DiaChi], [DienThoai]) VALUES (N'001  ', N'Nguyễn Văn Diện', N'21 Nam Kì Khởi Nghĩa', N'0904298335')
INSERT [dbo].[KHACH] ([MaKH], [HoTen], [DiaChi], [DienThoai]) VALUES (N'002  ', N'Trần Thị Vui', N'8 Võ Văn Ngân', N'0369297664')
INSERT [dbo].[KHACH] ([MaKH], [HoTen], [DiaChi], [DienThoai]) VALUES (N'003  ', N'Lý Hoàng Nam', N'21 Nam Kì Khởi Nghĩa', N'0365883605')
INSERT [dbo].[KHACH] ([MaKH], [HoTen], [DiaChi], [DienThoai]) VALUES (N'004  ', N'Hồ Duy Bảo', N'21 Nam Kì Khởi Nghĩa', N'0364686542')
GO
INSERT [dbo].[PHONG] ([MaPhong], [TinhTrang], [LoaiPhong], [DonGia]) VALUES (N'001  ', N'Rảnh', N'Đơn', 250000)
INSERT [dbo].[PHONG] ([MaPhong], [TinhTrang], [LoaiPhong], [DonGia]) VALUES (N'002  ', N'Rảnh', N'Đơn', 225000)
INSERT [dbo].[PHONG] ([MaPhong], [TinhTrang], [LoaiPhong], [DonGia]) VALUES (N'003  ', N'Rảnh', N'Đôi', 400000)
INSERT [dbo].[PHONG] ([MaPhong], [TinhTrang], [LoaiPhong], [DonGia]) VALUES (N'004  ', N'Rảnh', N'Đôi', 425000)
INSERT [dbo].[PHONG] ([MaPhong], [TinhTrang], [LoaiPhong], [DonGia]) VALUES (N'005  ', N'Rảnh', N'Đơn', 210000)
GO
ALTER TABLE [dbo].[DATPHONG]  WITH CHECK ADD  CONSTRAINT [FK_DATPHONG_KHACH] FOREIGN KEY([MaKH])
REFERENCES [dbo].[KHACH] ([MaKH])
GO
ALTER TABLE [dbo].[DATPHONG] CHECK CONSTRAINT [FK_DATPHONG_KHACH]
GO
ALTER TABLE [dbo].[DATPHONG]  WITH CHECK ADD  CONSTRAINT [FK_DATPHONG_PHONG] FOREIGN KEY([MaPhong])
REFERENCES [dbo].[PHONG] ([MaPhong])
GO
ALTER TABLE [dbo].[DATPHONG] CHECK CONSTRAINT [FK_DATPHONG_PHONG]
GO
ALTER TABLE [dbo].[PHONG]  WITH CHECK ADD  CONSTRAINT [CK_PHONG] CHECK  (([TinhTrang]=N'Bận' OR [TinhTrang]=N'Rảnh'))
GO
ALTER TABLE [dbo].[PHONG] CHECK CONSTRAINT [CK_PHONG]
GO

----------------*****----------------
--Stored Procedure
USE [QLKhachSan]
GO
--Q1
CREATE PROC spDatPhong(
	@makh char(5),
	@maphong char(5),
	@ngaydat datetime
)
AS
BEGIN
	--Dat MaDP ban dau = 0;
	DECLARE @madp int = 1

	--Tim MaDP lon nhat hien tai, MaDP = MaDP lon nhat hien tai + 1
	IF ((SELECT COUNT(*) FROM DATPHONG) <> 0)
		SET @madp = (SELECT Max(MaDatPhong) FROM DATPHONG) + 1
	
	-- Kiểm tra 3 dieu kien: MaKH ton tai, MaPhong ton tai, Phong phai ranh
	--Neu dung thi them thong tin Dat phong, cap nhat phong la Ban
	--Neu sai thi in ra thong bao
	IF (@makh IN (SELECT MaKH FROM KHACH)
		AND @maphong IN (SELECT MaPhong FROM PHONG)
		AND (SELECT TinhTrang FROM PHONG WHERE @maphong = MaPhong) = N'Rảnh'
		AND @madp NOT IN (SELECT MaDatPhong FROM DATPHONG))
	BEGIN
		INSERT INTO DATPHONG VALUES (@madp, @makh, @maphong, @ngaydat, NULL, NULL)
		UPDATE PHONG SET TinhTrang = N'Bận' WHERE MaPhong = @maphong
		print N'Đã đặt phòng thành công'
	END
	ELSE
		print N'Đặt phòng không hợp lệ'
END
go
EXEC spDatPhong '002', '004', '05/17/2022'
EXEC spDatPhong '001', '003', '05/10/2022'
EXEC spDatPhong '001', '002', '05/12/2022'
go
SELECT *
FROM DATPHONG
SELECT *
FROM PHONG
SELECT *
FROM KHACH
go
drop proc spDatPhong
go

--Q2
CREATE PROC spTraPhong(
	@madp int,
	@makh char(5)
)
AS
BEGIN
	--Kiem tra dieu kien xem dat phong ton tai khong
	IF (EXISTS (
		SELECT * 
		FROM DATPHONG DP
		WHERE @madp = DP.MaDatPhong AND @makh = DP.MaKH)
		AND (SELECT NgayTra FROM DATPHONG WHERE @madp = MaDatPhong AND @makh = MaKH) is NULL
		)
	--Neu ton tai thi update ngay tra, thanh tien va tinh trang phong
	--Neu khong thi bao loi khong ton tai
	BEGIN
		DECLARE @money float = (
			SELECT DonGia
			FROM PHONG P 
			JOIN DATPHONG DP ON DP.MaPhong = P.MaPhong
			WHERE @madp = DP.MaDatPhong AND @makh = DP.MaKH)
		UPDATE DATPHONG 
		SET NgayTra = getdate(),  ThanhTien = abs(datediff(day, NgayDat, getdate())) * @money
		WHERE @madp = MaDatPhong AND @makh = MaKH

		UPDATE PHONG
		SET TinhTrang = N'Rảnh'
		WHERE MaPhong = (
			SELECT MaPhong
			FROM DATPHONG
			WHERE @madp = MaDatPhong AND @makh = MaKH)	
		print N'Đã trả phòng thành công'
	END
	ELSE
		print N'Không thể trả phòng'
END
go
EXEC spTraPhong 1, '002'
EXEC spTraPhong 2, '001'
EXEC spTraPhong 5, '001'
go

EXEC spDatPhong '003', '004', '05/20/2022'
EXEC spDatPhong '004', '005', '05/14/2022'
go
