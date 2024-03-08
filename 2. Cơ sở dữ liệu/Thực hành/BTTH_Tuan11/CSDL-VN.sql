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

	